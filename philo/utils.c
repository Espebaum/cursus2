/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:16:33 by gyopark           #+#    #+#             */
/*   Updated: 2023/03/08 16:25:28 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char *str)
{
	int		cnt;

	cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	is_space(char c)
{
	if (c == 9 || c == 10 || c == 11
		|| c == 12 || c == 13 || c == 32)
		return (1);
	else
		return (0);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	len;

	len = 0;
	len = ft_strlen(s);
	write(fd, s, len);
	write(2, "\n", 1);
}

int	ft_atoi(char *str)
{
	long long	cnt;
	long long	is_minus;

	cnt = 0;
	is_minus = 1;
	while (*str)
	{
		if (is_space(*str))
			str++;
		else
			break ;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_minus *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		cnt *= 10;
		cnt += *str - '0';
		str++;
	}
	return (is_minus * cnt);
}
