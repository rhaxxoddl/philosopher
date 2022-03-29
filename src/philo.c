/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:51:39 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/29 18:04:54 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*even_philo(void *a)
{
	t_philo	*philo;
	int	num;
	int	i;

	philo = a;
	num = philo->philo_seq;
	i = -1;
	while (++i < 5)
	{
		// if (pthread_mutex_lock(arg->m[0]) != 0)
		// 	write(1, "no\n", 3);
		add_fork(philo, num);
		// pthread_mutex_unlock(arg->m[0]);
	}
	// pthread_mutex_lock(arg->m[arg->philo_seq]);
	philo->info->num_philo--;
	printf("num_philo : %d\n", philo->info->num_philo);
	// pthread_mutex_unlock(arg->m[arg->philo_seq]);
	return (0);
}

// void	*odd_philo(void *a)
// {
// 	t_philo_arg	*arg;
// 	int	num;
// 	// int	i;

// 	arg = a;
// 	num = arg->philo_seq;
// 	// i = -1;
// 	pthread_mutex_lock(arg->m[0]);
// 	add_fork(arg, num);
// 	pthread_mutex_unlock(arg->m[0]);
// 	// while (++i < 5)
// 	// {
// 	// 	printf("%p\n", arg->m);
// 	// 	pthread_mutex_lock(arg->m[1]);
// 	// 	printf("I'm odd %d\nI'm get %dfork!\n", m, arg->fork);
// 	// 	arg->fork++;
// 	// 	pthread_mutex_unlock(arg->m[1]);
// 	// }
// 	// pthread_mutex_lock(arg->m[arg->philo_seq]);
// 	arg->num_philo--;
// 	printf("num_philo : %d\n", arg->num_philo);
// 	// pthread_mutex_unlock(arg->m[arg->philo_seq]);
// 	return (0);
// }

void	add_fork(t_info *info, int num)
{
	if (pthread_mutex_lock(info->m[0]) != 0)
		write(1, "no\n", 3);
	printf("philo %d : get %dfork!\n", num, info->fork);
	info->fork++;
	pthread_mutex_unlock(info->m[0]);
}
