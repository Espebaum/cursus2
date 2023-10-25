#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr_fd_re(int n, int fd)
{
	long long	num;
	char		c;

	num = (long long) n; // num이 long long 아니어도 상관 없다
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	if (num >= 10)
		ft_putnbr_fd_re(num / 10, fd);
	c = num % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd_lo(int n, int fd)
{
	long long	num;
	long long	num2;
	int			idx;
	char		*buf;
	int			i;

	idx = 0;
	i = 0;
	num = (long long) n;	
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	num2 = num;
	while (num != 0)
	{
		idx++;
		num /= 10;
	}
	buf = (char *) malloc(sizeof(char) * (idx + 1));
	while (num2 != 0)
	{
		buf[i++] = num2 % 10 + '0';
		num2 /= 10;
	}
	while (idx > 0)
		write(1, &buf[--idx], 1);
}

static size_t	ft_len(int *num)
{
	int				len;
	long long		tmp;

	len = 0;
	if (*num <= 0)
	{
		len += 1;
		*num *= -1;
	}
	tmp = *num;
	while (tmp)
	{
		len += 1;
		tmp /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t		len;
	char		*ascii;
	long long	num;

	num = (long long) n;
	len = ft_len(&num);
	ascii = (char *) malloc(sizeof(char) * (len + 1));
	if (ascii == NULL)
		return (NULL);
	ascii[len] = '\0';
	ascii[0] = '-';
	while (1)
	{
		ascii[--len] = num % 10 + '0';
		num /= 10;
		if (num == 0)
			break ;
	}
	return (ascii);
}

int main(int argc, char **argv)
{
	long long num = -1234;
	long long num2 = 2147483647;
	int num3 = 2147483648;
	long long num4 = -2147483649;
	long long num5 = -2147483648;
	ft_putnbr_fd_re(num, 1);
	write(1, "\n", 1);
	ft_putnbr_fd_lo(num, 1);
	write(1, "\n", 1);
	ft_putnbr_fd_re(num2, 1);
	write(1, "\n", 1);
	ft_putnbr_fd_lo(num2, 1);
	write(1, "\n", 1);
	write(1, "123\n", 4);
	ft_putnbr_fd_re(num3, 1);
	write(1, "\n", 1);
	ft_putnbr_fd_lo(num3, 1);
	write(1, "\n", 1);	
	ft_putnbr_fd_re(num4, 1);
	write(1, "\n", 1);
	ft_putnbr_fd_lo(num4, 1);
	write(1, "\n", 1);
	ft_putnbr_fd_re(num5, 1);
	write(1, "\n", 1);
	ft_putnbr_fd_lo(num5, 1);
	write(1, "\n", 1);
	printf("ft_itoa\n");
	printf("%s\n", ft_itoa(num));
	printf("%s\n", ft_itoa(num2));
	printf("%s\n", ft_itoa(num3));
	printf("%s\n", ft_itoa(num4));
	printf("%s\n", ft_itoa(num5));

	int num9 = 2147483648;
	printf("%d\n", num9);
}
