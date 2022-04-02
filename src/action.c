/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:30:07 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/02 21:25:15 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	routine(t_philo *philo)
{
	if (philo->philo_seq % 2 == 0)
	{
		if (even_eat(philo) == 0)
			return (0);
		sleep_and_think(philo->info, philo->philo_seq);
	}
	else
	{
		if (odd_eat(philo) == 0)
			return (0);
		sleep_and_think(philo->info, philo->philo_seq);
	}
	return (1);
}

int	even_eat(t_philo *philo)
{
	if (take_fork_l(philo) == 0)
		return (0);
	if (take_fork_r(philo) == 0)
		return (0);
	philo->last_eat = get_time();
	philo->num_eat++;
	print_state(philo->info, philo->philo_seq, 1);
	ft_usleep(philo->info->time_eat);
	if (drop_fork_l(philo) == 0)
		return (0);
	if (drop_fork_r(philo) == 0)
		return (0);
	return (1);
}

int	odd_eat(t_philo *philo)
{
	if (take_fork_r(philo) == 0)
		return (0);
	if (take_fork_l(philo) == 0)
		return (0);
	philo->last_eat = get_time();
	philo->num_eat++;
	print_state(philo->info, philo->philo_seq, 1);
	ft_usleep(philo->info->time_eat);
	if (drop_fork_r(philo) == 0)
		return (0);
	if (drop_fork_l(philo) == 0)
		return (0);
	return (1);
}

void	sleep_and_think(t_info *info, int seq)
{
	print_state(info, seq, 2);
	ft_usleep(info->time_sleep);
	print_state(info, seq, 3);
}
