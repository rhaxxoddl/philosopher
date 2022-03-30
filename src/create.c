/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:55:41 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/30 11:18:49 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_info *info)
{
	int	status;
	int	i;
	t_philo **philo;

	status = 0;
	i = -1;
	philo = 0;
	philo = init_philo(info);
	if (philo == 0)
		return (0);
	while (++i < info->num_philo)
	{
		// if (i % 2 == 0)
			status = pthread_create(info->t_id[i], NULL, even_philo, (void *)philo[i]);
		// else
		// 	status = pthread_create(&(arg->t_id[i]), NULL, odd_philo, (void *)&i);
		if (status < 0)
			p_error("Error\n: Failed create thread", info);
	}
	i = -1;
	while (++i < info->num_philo)
	{
		if (pthread_detach(*(info->t_id[i])) != 0)
			p_error("Error\n: Failed detach thread", info);
	}
	while (info->del_philo != info->num_philo)
	{
		usleep(1);
		// printf("sleep\n");
	}
	return (1);
}

t_philo	**init_philo(t_info *info)
{
	t_philo	**philo;
	int		i;

	philo = (t_philo **)ft_calloc(info->num_philo, sizeof(t_philo *));
	if (philo == 0)
		return (0);
	i = -1;
	while (++i < info->num_philo)
	{
		philo[i] = (t_philo *)ft_calloc(1,sizeof(t_philo *));
		if (philo[i] == 0)
		{
			free_t_philo(philo);
			return (0);
		}
		philo[i]->info = info;
		philo[i]->philo_seq = i + 1;
		philo[i]->num_eat = info->num_eat;
		
	}
	return (philo);
}

