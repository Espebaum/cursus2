/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:53:33 by gyopark           #+#    #+#             */
/*   Updated: 2023/03/07 21:24:42 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pass_time(long wait_time, t_arg *arg)
{
	long	start;
	long	now;

	start = ft_get_time();
	while (!check_finish(arg))
	{
		now = ft_get_time();
		if (now - start >= wait_time)
			break ;
		usleep(100);
	}
}

void	print_philo(t_arg *arg, t_philo *philo, char *str, int flag)
{
	long	now;

	pthread_mutex_lock(&arg->print);
	if (!check_finish(arg))
	{
		now = ft_get_time();
		printf("%ld %d %s\n", now - philo->start, philo->id + 1, str);
		if (flag == 1)
			change_finish(arg);
	}
	pthread_mutex_unlock(&arg->print);
}

void	monitoring(t_arg *arg, t_philo *philo)
{
	int		tmp;
	int		i;
	long	now;

	while (!check_finish(arg))
	{
		tmp = (int)get_share(arg, 0, 0);
		if (arg->max_eat_count && arg->max_eat_count == tmp)
		{
			change_finish(arg);
			break ;
		}
		i = -1;
		while (++i < arg->philo_num)
		{
			now = get_share(arg, &philo[i], 1);
			if (now >= arg->time_to_die)
			{
				print_philo(arg, &philo[i], "died", 1);
				break ;
			}
		}
	}
}

int	philo_eat(t_arg *arg, t_share *share, t_philo *philo)
{
	if (check_fork(arg, share, philo->id))
	{
		pthread_mutex_lock(&(share->forks[philo->left]));
		print_philo(arg, philo, "has taken a fork", 0);
		if (arg->philo_num != 1)
		{
			pthread_mutex_lock(&(share->forks[philo->right]));
			print_philo(arg, philo, "has taken a fork", 0);
			print_philo(arg, philo, "is eating", 0);
			pthread_mutex_lock(&arg->status);
			philo->last_eat_time = ft_get_time();
			philo->eat_count++;
			share->fork_status[philo->right] = 0;
			share->fork_status[philo->left] = 0;
			pthread_mutex_unlock(&arg->status);
			pass_time((long)arg->time_to_eat, arg);
			pthread_mutex_unlock(&(share->forks[philo->right]));
			pthread_mutex_unlock(&(share->forks[philo->left]));
			return (1);
		}
		pthread_mutex_unlock(&(share->forks[philo->left]));
		return (0);
	}
	return (0);
}

void	*philo_loof(void *argv)
{
	t_philo	*philo;
	t_arg	*arg;
	t_share	*share;

	philo = argv;
	arg = philo->arg;
	share = philo->share;
	if (philo->id % 2)
		usleep(1000);
	while (!check_finish(arg))
	{
		if (!philo_eat(arg, share, philo))
			continue ;
		if (arg->max_eat_count && (arg->max_eat_count == philo->eat_count))
		{
			pthread_mutex_lock(&arg->status);
			arg->eat_finished++;
			pthread_mutex_unlock(&arg->status);
			break ;
		}
		print_philo(arg, philo, "is sleeping", 0);
		pass_time((long)arg->time_to_sleep, arg);
		print_philo(arg, philo, "is thinking", 0);
	}
	return (0);
}
