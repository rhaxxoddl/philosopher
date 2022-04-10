/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:55:41 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/10 19:09:53 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philo(t_info *info, t_philo *philo)
{
	int		i;
	int		full_philo;

	while (1)
	{
		i = 0;
		full_philo = 0;
		while (++i <= info->num_philo)
		{
			if (info->req_eat >= 0 && philo[i].num_eat >= info->req_eat)
				full_philo++;
			if ((get_time() - philo[i].last_eat) > philo[i].info->time_die)
			{
				print_state(&(philo[i]), 4);
				return ;
			}
		}
		if (full_philo >= info->num_philo)
		{
			info->is_end = 1;
			return ;
		}
	}
	return ;
}

t_philo	*create_philo(t_info	*info)
{
	t_philo	*philo;
	int		status;
	int		i;

	philo = 0;
	status = 0;
	i = 0;
	philo = init_philo(info);
	while (++i <= info->num_philo)
	{
		status = pthread_create(&(info->t_id[i]), NULL,
				routine, (void *)&philo[i]);
		if (status < 0)
			return (0);
	}
	return (philo);
}

t_philo	*init_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)ft_calloc(info->num_philo + 2, sizeof(t_philo));
	if (philo == 0)
		return (0);
	i = -1;
	while (++i <= info->num_philo)
	{
		philo[i].info = info;
		philo[i].philo_seq = i;
		philo[i].num_eat = 0;
		philo[i].last_eat = info->start_time;
	}
	return (philo);
}
