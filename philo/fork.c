/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:33:50 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/11 10:25:45 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork_l(t_philo *philo)
{
	if (pthread_mutex_lock(&(philo->info->m[philo->philo_seq])) == -1)
		return (0);
	print_state(philo, FORK);
	philo->info->fork[philo->philo_seq] = philo->philo_seq;
	return (1);
}

int	take_fork_r(t_philo *philo)
{
	if (philo->philo_seq == 1)
	{
		if (pthread_mutex_lock(&(philo->info->m[philo->info->num_philo])) == -1)
			return (0);
		print_state(philo, FORK);
		philo->info->fork[philo->info->num_philo] = philo->philo_seq;
		return (1);
	}
	else
	{
		if (pthread_mutex_lock(&(philo->info->m[philo->philo_seq - 1])) == -1)
			return (0);
		print_state(philo, FORK);
		philo->info->fork[philo->philo_seq - 1] = philo->philo_seq;
		return (1);
	}
}

int	drop_fork_l(t_philo *philo)
{
	philo->info->fork[philo->philo_seq] = 0;
	if (pthread_mutex_unlock(&(philo->info->m[philo->philo_seq])) == -1)
		return (0);
	return (1);
}

int	drop_fork_r(t_philo *philo)
{
	if (philo->philo_seq == 1)
	{
		philo->info->fork[philo->info->num_philo] = 0;
		if (pthread_mutex_unlock(&(philo->info->m[philo->info->num_philo]))
			== -1)
			return (0);
		return (1);
	}
	else
	{
		philo->info->fork[philo->philo_seq - 1] = 0;
		if (pthread_mutex_unlock(&(philo->info->m[philo->philo_seq - 1])) == -1)
			return (0);
		return (1);
	}
}
