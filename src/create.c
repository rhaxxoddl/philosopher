/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:55:41 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/01 17:15:14 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_info *info)
{
	int	status;
	int	i;
	t_philo **philo;

	status = 0;
	i = 0;
	philo = 0;
	philo = init_philo(info);
	if (philo == 0)
		return (0);
	status = pthread_create(info->t_id[i], NULL, check_die, (void *)philo);
	if (status < 0)
		p_error("Error\n: Failed create thread", info, philo);
		
	while (++i < info->num_philo)
	{
		if (i % 2 == 1)
			status = pthread_create(info->t_id[i], NULL, even_philo, (void *)philo[i]);
		else
			status = pthread_create(info->t_id[i], NULL, odd_philo, (void *)philo[i]);
		if (status < 0)
			p_error("Error\n: Failed create thread", info, philo);
	}
	i = -1;
	while (++i < info->num_philo)
	{
		if (pthread_detach(*(info->t_id[i])) != 0)
			p_error("Error\n: Failed detach thread", info, philo);
	}
	while (info->del_philo != info->num_philo)
	{
		if (info->req_eat < 0 && info->del_philo > 0)
			break;
		usleep(1);
	}
	free_t_philo(philo);
	return (1);
}

t_philo	**init_philo(t_info *info)
{
	t_philo	**philo;
	int		i;

	philo = (t_philo **)ft_calloc(info->num_philo + 1, sizeof(t_philo *));
	if (philo == 0)
		return (0);
	i = -1;
	while (++i < info->num_philo)
	{
		philo[i] = (t_philo *)ft_calloc(1,sizeof(t_philo));
		if (philo[i] == 0)
		{
			free_t_philo(philo);
			return (0);
		}
		philo[i]->info = info;
		philo[i]->philo_seq = i + 1;
		philo[i]->num_eat = info->req_eat;
	}
	return (philo);
}

void	*check_die(t_philo **philo)
{
	int	i;
	while (1)
	{
		i = 1;
		while (i <= philo[i]->info->num_philo)
		{
			if ((get_time() - philo[i]->last_eat) > philo[i]->info->time_die)
			{
				print_state(philo[i]->info, philo[i]->philo_seq, 4);
				philo[i]->info->del_philo++;
				return (0);
			}
			i++;
		}
	}
	return (0);
}