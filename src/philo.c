/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:51:39 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/31 21:12:55 by sanjeon          ###   ########.fr       */
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
		routine(philo);
		if (check_die(philo) == 0)
		{
			print_state(philo->info, philo->philo_seq, 4);
			return (0);
		}
		++i;
		if (philo->info->req_eat > 0 && i >= philo->info->req_eat)
		{
			philo->info->del_philo++;
			return (0);
		}
	}
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
		routine(philo);
		if (check_die(philo) == 0)
			return (0);
		++i;
		if (philo->info->req_eat > 0 && i >= philo->info->req_eat)
		{
			philo->info->del_philo++;
			return (0);
		}
	}
	return (0);
}