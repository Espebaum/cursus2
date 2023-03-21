#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	cnt = 0;

	while (*str++)
		cnt++;
	return (cnt);
}

void	ft_putstr(char *str)
{
	int	len;

	len = strlen(str);
	write(2, str, len);
}

int	ft_execute(char **argv, int i, int tmp_fd, char **envp)
{
	argv[i] = NULL;	//마지막 인자가 NULL이 아닌 경우(;), 바뀌게 됨
	close(tmp_fd); //안쓰는 fd를 닫음
	execve(argv[0], argv, envp);
	ft_putstr("error: cannot execute "); //실행이 실패했다면
	ft_putstr(argv[0]);
	ft_putstr("\n");
	return (1);
}

int main(int argc, char **argv, char **envp)
{
	(void) argc;	//argc는 안씀
	int	i = 0;		//반복문 돌릴 i
	int	pid = 0;	//pid
	int	tmp_fd = dup(0); //fd[0]으로 갖다 쓰거나, 표준 입력
	int fd[2];			//파이프 fd

	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1]; 
		// a.out 다음 인자로 처음 포인터를 옮김 
		// 첫번째 while문이 아니라면 ;나 | 다음 인자로 포인터를 옮김
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
		// argv[i]가 NULL도 아니고 ;도 아니고 |도 아닐 때 i++
			i++;
		if (strcmp(argv[0], "cd") == 0) // 1번 경우) a.out 다음이 cd 일때
		{
			if (i != 2) // cd 다음 인자가 없거나 두개 이상이 들어올 때
				ft_putstr("error: cd: bad argument\n");
			else if (chdir(argv[1]) != 0) // chdir 정상 반환값 => 0
			{
				ft_putstr("error: cannot execute ");
				ft_putstr(argv[1]);
				ft_putstr("\n");
			}
		}
		else if (argv != &argv[i] && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		//2번 경우) 마지막 명령줄, 2번과 3번이 바뀌면 세그가 난다...
		//인자가 제대로 들어와서 i++했으면 자연스럽게 &argv[i]은 NULL의 주소가 된다
		//argv[i]가 NULL이나 ;라면 마지막 명령줄임을 의미
		//읽기 파이프에서 받아 표준 출력으로 쏴주면 된다
		{
			pid = fork();
			if (pid < 0) //fork가 실패했을 경우
			{
				ft_putstr("error: fatal\n");
				exit(0);
			}
			if (pid == 0) //자식 프로세스일때
			{
				dup2(tmp_fd, 0); 
				// 표준 입력을 tmp_fd로 받도록 변경(첫번째 while문이라면 STDIN, 그 이후면 fd[0])
				if (ft_execute(argv, i, tmp_fd, envp))
					return (1);
			}
			else // 부모 프로세스일때
			{
				close(tmp_fd); // fd[0]으로 받았기 때문에 tmp_fd는 안쓰니까 닫아둠
				waitpid(-1, 0, 0); // 첫번째 인자 -1 => 되는대로 기다림
				tmp_fd = dup(0); // 마지막으로 tmp_fd를 0으로 되돌리면서 닫아줌
			}
		}
		else if (argv != &argv[i] && strcmp(argv[i], "|") == 0)
		//3번 경우) 중간 명령줄
		//argv[i]이 |라면 명령줄 하나이며 끊고 프로세스를 열면 됨
		{
			if (pipe(fd) < 0)
			{
				ft_putstr("error: fatal\n");
				exit(0);
			}
			pid = fork();
			if (pid < 0)
			{
				ft_putstr("error: fatal\n");
				exit(0);
			}
			if (pid == 0)
			{
				dup2(tmp_fd, 0);
				// 표준 입력을 tmp_fd로 받도록 변경(첫번째 while문이라면 STDIN, 그 이후면 fd[0])
				dup2(fd[1], 1);
				// 쓰기 파이프에 쓸 것이기 때문에 출력을 쓰기 파이프로 변경
				close(fd[0]); // 읽기 파이프는 안쓸거기 때문에 닫음
				close(fd[1]); // 마찬가지로 쓰기 파이프도 안쓰니까 닫음
				if (ft_execute(argv, i, tmp_fd, envp))
					return (1);
			}
			else
			{
				close(tmp_fd); // fd[0]으로 받았기 때문에 tmp_fd는 닫음
				close(fd[1]); //부모는 받기만 하고 쓰진 않기 때문에 쓰기 파이프는 닫음
				waitpid(-1, 0, 0); 
				tmp_fd = dup(fd[0]); 
				// 다음 while문에 넘겨줄 읽기 파이프 fd값을 tmp_fd에 복사
				close(fd[0]); //다 쓴 읽기 파이프는 닫음
			}
		}
	}
	close(tmp_fd); // 다쓴 tmp_fd를 닫으면서 리턴
	return (0);
}
