/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:09:52 by gyopark           #+#    #+#             */
/*   Updated: 2023/03/07 21:25:31 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	free_thread(t_arg *arg, t_share *share, t_philo *philo, int result)
{
	int	i;

	pthread_mutex_destroy(&arg->print);
	pthread_mutex_destroy(&arg->status);
	i = 0;
	while (i < arg->philo_num)
		pthread_mutex_destroy(&share->forks[i++]);
	if (share->fork_status)
		free(share->fork_status);
	if (share->forks)
		free(share->forks);
	if (philo)
		free(philo);
	return (result);
}

int	ft_philo(t_arg *arg, t_share *share, t_philo *philo)
{
	int		i;

	i = 0;
	while (i < arg->philo_num)
	{
		philo[i].last_eat_time = ft_get_time();
		if (pthread_create(&philo[i].thread, NULL, philo_loof, &philo[i]))
			return (free_thread(arg, share, philo, 5));
		i++;
	}
	monitoring(arg, philo);
	i = 0;
	while (i < arg->philo_num)
		pthread_join(philo[i++].thread, NULL);
	return (free_thread(arg, share, philo, 0));
}

int	print_err(int result)
{
	if (result == 1)
		ft_putendl_fd("Invalid number of arguments\n", 2);
	if (result == 2)
		ft_putendl_fd("Invalid value of arguments\n", 2);
	if (result == 3)
		ft_putendl_fd("Mutex init error\n", 2);
	if (result == 4)
		ft_putendl_fd("Malloc error\n", 2);
	if (result == 5)
		ft_putendl_fd("Create error\n", 2);
	return (result);
}

int	main(int argc, char **argv)
{
	t_arg	arg;
	t_share	share;
	t_philo	*philo;
	int		result;

	if (argc != 5 && argc != 6)
		return (print_err(1));
	memset(&arg, 0, sizeof(t_arg));
	memset(&share, 0, sizeof(t_share));
	result = ft_arg_init(argc, argv, &arg, &share);
	if (result)
		return (print_err(result));
	result = init_philo(&arg, &share, &philo);
	if (result)
		return (print_err(result));
	result = ft_philo(&arg, &share, philo);
	if (result)
		return (print_err(result));
	return (result);
}
