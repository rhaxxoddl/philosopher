/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:55:41 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/29 18:14:05 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo(t_info *info, pthread_t **t_id)
{
	int	status;
	int	i;

	status = 0;
	i = -1;
	while (++i < info->num_philo)
	{
		t_id[i] = init_philo(info, i + 1);
		// if (i % 2 == 0)
			status = pthread_create(&(t_id[i]), NULL, even_philo, (void *)info);
		// else
		// 	status = pthread_create(&(arg->t_id[i]), NULL, odd_philo, (void *)&i);
		if (status < 0)
			p_error("Error\n: Failed create thread", info);
		if (pthread_detach(t_id[i]) != 0)
			p_error("Error\n: Failed detach thread", info);
	}
}

t_philo	*init_philo(t_info *info, int seq)
{
	t_philo	*philo;

	philo = (t_philo *)ft_calloc(1, sizeof(t_philo));
	if (philo == 0)
		return (0);
	philo->info = info;
	philo->philo_seq = seq;
	philo->num_eat = info->num_eat;
}

