/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:37:36 by gyopark           #+#    #+#             */
/*   Updated: 2023/02/28 20:44:03 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	ft_arg_init(int argc, char **argv, t_arg *arg)
{
	int	i;

	i = 0;
	if (check_argv(argc, argv, &arg))
		return (3);
	arg->max_eat_times = -1;
	if (argc == 6)
	{
		arg->max_eat_times = ft_atoi(argv[5]);
		if (arg->max_eat_times == 0)
			return (3);
	}
	arg->fork_status = (int *)malloc(sizeof(int) * arg->philo_num);
	if (arg->fork_status == NULL)
		return (3);
	while (i < arg->philo_num)
		arg->fork_status[i++] = 0;
	arg->is_safe = 1;
	if (ft_philo_init(arg) || ft_mutex_init(arg))
		return (3);
	return (0);
}
