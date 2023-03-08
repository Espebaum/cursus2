/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:17:07 by gyopark           #+#    #+#             */
/*   Updated: 2023/03/08 17:35:16 by gyopark          ###   ########.fr       */
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
	int				max_eat_count;
	int				eat_finished;
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

//init functions
int		ft_arg_init(int argc, char **argv, t_arg *arg, t_share *share);
int		init_philo(t_arg *arg, t_share *share, t_philo **philo);

//thread functions
void	*philo_loof(void *argv);
void	monitoring(t_arg *arg, t_philo *philo);
long	get_share(t_arg *arg, t_philo *philo, int flag);
void	change_finish(t_arg *arg);
int		check_fork(t_arg *arg, t_share *share, int id);
int		check_finish(t_arg *arg);	
void	print_philo(t_arg *arg, t_philo *philo, char *str, int flag);

//util functions
void	ft_putendl_fd(char *s, int fd);
long	ft_get_time(void);
int		ft_isdigit(int c);
int		ft_atoi(char *str);

//freeing function
int		free_thread(t_arg *arg, t_share *share, t_philo *philo, int result);

#endif