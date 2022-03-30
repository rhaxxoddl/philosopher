/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:51:39 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/30 11:51:41 by sanjeon          ###   ########.fr       */
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
		add_fork(philo->info, philo->philo_seq, 0);
	}
	pthread_mutex_lock(philo->info->m[1]);
	philo->info->del_philo++;
	printf("del_philo : %d\n", philo->info->del_philo);
	pthread_mutex_unlock(philo->info->m[1]);
	return (0);
}

void	*odd_philo(void *a)
{
	t_philo	*philo;
	int	i;

	philo = a;
	i = -1;
	while (++i < 5)
	{
		add_fork(philo->info, philo->philo_seq, 1);
	}
	pthread_mutex_lock(philo->info->m[1]);
	philo->info->del_philo++;
	printf("del_philo : %d\n", philo->info->del_philo);
	pthread_mutex_unlock(philo->info->m[1]);
	return (0);
}

void	add_fork(t_info *info, int seq, int n)
{
	if (pthread_mutex_lock(info->m[0]) != 0)
		write(1, "no\n", 3);
	if (n == 0)
		printf("even philo %d : get %dfork!\n", seq, info->fork);
	else
		printf("odd philo %d : get %dfork!\n", seq, info->fork);
	info->fork++;
	pthread_mutex_unlock(info->m[0]);
}

void	print_info(t_philo *philo)
{
	printf("philo_seq : %d\n", philo->philo_seq);
	printf("fork : %d\n", philo->info->fork);
}