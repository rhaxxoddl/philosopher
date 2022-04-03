/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:51:39 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/03 12:52:21 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*even_philo(void *a)
{
	t_philo	*philo;
	int		i;

	philo = a;
	i = 0;
	while (1)
	{
		routine(philo);
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
	int		i;

	philo = a;
	i = 0;
	while (1)
	{
		routine(philo);
		++i;
		if (philo->info->req_eat > 0 && i >= philo->info->req_eat)
		{
			philo->info->del_philo++;
			return (0);
		}
	}
	return (0);
}
