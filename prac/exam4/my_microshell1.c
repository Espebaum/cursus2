#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	cnt = 0;
	while (*str++)
		cnt++;
	return cnt;
}

void	ft_putstr(char *str)
{
	int	len = ft_strlen(str);
	write(2, str, len);
}

int	ft_execute(char **argv, int i, int tmp_fd, char **envp)
{
	argv[i] = NULL;
	close(tmp_fd);
	execve(argv[0], argv, envp);
	ft_putstr("error: cannot execute ");
	ft_putstr(argv[0]);
	ft_putstr("\n");
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	(void)	argc;
	int		i = 0;
	int		pid = 0;
	int		tmp_fd = dup(0);
	int		fd[2];

	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
		{
			if (i != 2)
				ft_putstr("error: cd: bad argument\n");
			else if (chdir(argv[1]) != 0)
			{
				ft_putstr("error: cannot execute ");
				ft_putstr(argv[1]);
				ft_putstr("\n");
			}
		}
		else if (argv != &argv[i] && (argv[i] == NULL || strcmp(argv[i], ";") == 0)) //last command
		{
			pid = fork();
			if (pid < 0)
			{
				ft_putstr("error: fatal\n");
				exit(0);
			}
			else if (pid == 0)
			{
				dup2(tmp_fd, 0);
				if (ft_execute(argv, i, tmp_fd, envp))
					return (1);
			}
			else
			{
				close(tmp_fd);
				waitpid(-1, 0, 0);
				tmp_fd = dup(0);
			}
		}
		else if (argv != &argv[i] && strcmp(argv[i], "|") == 0) //first, mid command(open pipe)
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
			else if (pid == 0)
			{
				dup2(tmp_fd, 0);
				dup2(fd[1], 1);
				close(fd[0]);
				close(fd[1]);
				if (ft_execute(argv, i, tmp_fd, envp))
					return (1);
			}
			else
			{
				close(tmp_fd);
				close(fd[1]);
				waitpid(-1, 0, 0);
				dup2(tmp_fd, fd[0]);
				close(fd[0]);
			}
		}
	}
	close(tmp_fd);
	return (0);
}
