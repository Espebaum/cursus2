/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:14:05 by gyopark           #+#    #+#             */
/*   Updated: 2023/03/08 21:08:49 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_share(t_arg *arg, t_philo *philo, int flag)
{
	long	ret;

	pthread_mutex_lock(&arg->status);
	if (!flag)
		ret = arg->eat_finished;
	else
		ret = ft_get_time() - philo->last_eat_time;
	pthread_mutex_unlock(&arg->status);
	return (ret);
}

void	change_finish(t_arg *arg)
{
	pthread_mutex_lock(&arg->finish_check);
	arg->finish = 1;
	pthread_mutex_unlock(&arg->finish_check);
}

int	check_fork(t_arg *arg, t_share *share, int id)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&arg->status);
	if (!share->fork_status[id]
		&& !share->fork_status[(id + 1) % arg->philo_num])
	{
		share->fork_status[id] = 1;
		share->fork_status[(id + 1) % arg->philo_num] = 1;
		ret = 1;
	}
	pthread_mutex_unlock(&arg->status);
	return (ret);
}

int	check_finish(t_arg *arg)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&arg->finish_check);
	if (arg->finish)
		ret = 1;
	pthread_mutex_unlock(&arg->finish_check);
	return (ret);
}
