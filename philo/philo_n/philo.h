/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:17:07 by gyopark           #+#    #+#             */
/*   Updated: 2023/02/28 20:24:54 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_arg
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_count;
	int				eat_finshed;
	int				finish;
	pthread_mutex_t	status;
	pthread_mutex_t	print;
	pthread_mutex_t	finish_check;
}	t_arg;

typedef struct s_share
{
	int				*fork_status;
	pthread_mutex_t	*forks;
}	t_share;

typedef struct s_philo
{
	int			id;
	long		start;
	int			right;
	int			left;
	int			eat_count;
	long		last_eat_time;
	pthread_t	thread;
	t_arg		*arg;
	t_share		*share;
}	t_philo;


#endif