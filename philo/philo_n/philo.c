/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:09:52 by gyopark           #+#    #+#             */
/*   Updated: 2023/02/28 20:48:41 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"


int	main(int argc, char **argv)
{
	t_arg	arg;
	t_philo	philo;
	int		errno;

	if (argc != 5 && argc != 6)
		return (print_err("argument error\n", 3));
	memset(&arg, 0, sizeof(t_arg));
	errno = ft_arg_init(argc, argv, &arg);
	if (errno)
		return (print_err("arg init error\n", errno));
	
	if (errno)
		return (print_err("philo start error\n", errno));
	return (0);
}
