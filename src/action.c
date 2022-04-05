/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:30:07 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/05 11:19:23 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *a)
{
	t_philo	*philo;

	philo = a;
	while (1)
	{
		if (philo->info->req_eat >= 0
			&& philo->num_eat == philo->info->req_eat)
			philo->info->del_philo++;
		if (philo->philo_seq % 2 == 0)
		{
			if (even_eat(philo) == 0)
				perror("Failed even_eat!");
		}
		else
		{
			usleep(100);
			if (odd_eat(philo) == 0)
				perror("Failed even_eat!");
		}
		sleep_and_think(philo);
	}
	return (0);
}

int	odd_eat(t_philo *philo)
{
	if (take_fork_l(philo) == 0)
		return (0);
	if (take_fork_r(philo) == 0)
		return (0);
	print_state(philo, 1);
	ft_usleep(philo->info->time_eat);
	if (drop_fork_l(philo) == 0)
		return (0);
	if (drop_fork_r(philo) == 0)
		return (0);
	return (1);
}

int	even_eat(t_philo *philo)
{
	if (take_fork_r(philo) == 0)
		return (0);
	if (take_fork_l(philo) == 0)
		return (0);
	print_state(philo, 1);
	ft_usleep(philo->info->time_eat);
	if (drop_fork_r(philo) == 0)
		return (0);
	if (drop_fork_l(philo) == 0)
		return (0);
	return (1);
}

void	sleep_and_think(t_philo *philo)
{
	print_state(philo, 2);
	ft_usleep(philo->info->time_sleep);
	print_state(philo, 3);
}
