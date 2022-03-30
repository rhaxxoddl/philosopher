/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:51:39 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/30 11:18:44 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*even_philo(void *a)
{
	t_philo	*philo;
	int	i;

	philo = a;
	i = -1;
	while (++i < 5)
	{
		// if (pthread_mutex_lock(philo->info->m[0]) != 0)
		// 	write(1, "no\n", 3);
		add_fork(philo->info, philo->philo_seq);
		// pthread_mutex_unlock(philo->info->m[0]);
	}
	// pthread_mutex_lock(arg->m[arg->philo_seq]);
	philo->info->del_philo++;
	printf("del_philo : %d\n", philo->info->del_philo);
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

void	add_fork(t_info *info, int seq)
{
	if (pthread_mutex_lock(info->m[0]) != 0)
		write(1, "no\n", 3);
	printf("philo %d : get %dfork!\n", seq, info->fork);
	info->fork++;
	pthread_mutex_unlock(info->m[0]);
}

void	print_info(t_philo *philo)
{
	printf("philo_seq : %d\n", philo->philo_seq);
	printf("fork : %d\n", philo->info->fork);
}