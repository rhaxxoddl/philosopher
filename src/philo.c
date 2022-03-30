/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:51:39 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/30 18:51:21 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*even_philo(void *a)
{
	t_philo	*philo;
	int	i;

	philo = a;
	i = 0;
	while (1)
	{
		even_eat(philo->info, philo->philo_seq);
		++i;
		if (philo->info->req_eat > 0 && i >= philo->info->req_eat)
			break ;
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
	i = 0;
	while (1)
	{
		odd_eat(philo->info, philo->philo_seq);
		++i;
		if (philo->info->req_eat > 0 && i >= philo->info->req_eat)
			break ;
	}
	pthread_mutex_lock(philo->info->m[1]);
	philo->info->del_philo++;
	printf("del_philo : %d\n", philo->info->del_philo);
	pthread_mutex_unlock(philo->info->m[1]);
	return (0);
}

// void	print_info(t_philo *philo)
// {
// 	printf("philo_seq : %d\n", philo->philo_seq);
// 	printf("fork : %d\n", philo->info->fork);
// }