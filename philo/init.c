/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:37:36 by gyopark           #+#    #+#             */
/*   Updated: 2023/03/07 21:11:30 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_arg *arg, t_share *share, t_philo **philo)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * arg->philo_num);
	if (!*philo)
		return (free_thread(arg, share, 0, 4));
	i = -1;
	while (++i < arg->philo_num)
	{
		(*philo)[i].id = i;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % arg->philo_num;
		(*philo)[i].eat_count = 0;
		(*philo)[i].start = ft_get_time();
		(*philo)[i].arg = arg;
		(*philo)[i].share = share;
	}
	return (0);
}

int	init_share(t_arg *arg, t_share *share)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&arg->finish_check, NULL))
		return (3);
	if (pthread_mutex_init(&arg->print, NULL))
		return (3);
	if (pthread_mutex_init(&arg->status, NULL))
		return (3);
	share->fork_status = malloc(sizeof(int) * arg->philo_num);
	if (!share->fork_status)
		return (4);
	memset(share->fork_status, 0, sizeof(int) * arg->philo_num);
	share->forks = malloc(sizeof(pthread_mutex_t) * arg->philo_num);
	if (!share->forks)
		return (4);
	i = -1;
	while (++i < arg->philo_num)
	{
		if (pthread_mutex_init(&share->forks[i], NULL))
			return (4);
	}
	return (0);
}

int	check_is_num(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (1);
	return (0);
}

int	check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i != argc)
		if (check_is_num(argv[i]))
			return (1);
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0
		|| ft_atoi(argv[4]) < 0)
		return (1);
	if (argc == 6)
		if (ft_atoi(argv[5]) < 1)
			return (1);
	return (0);
}

int	ft_arg_init(int argc, char **argv, t_arg *arg, t_share *share)
{
	int		ret;

	if (check_argv(argc, argv))
		return (2);
	arg->philo_num = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	arg->max_eat_count = -1;
	if (argc == 6)
		arg->max_eat_count = ft_atoi(argv[5]);
	ret = init_share(arg, share);
	if (ret)
		return (free_thread(arg, share, 0, ret));
	return (0);
}
