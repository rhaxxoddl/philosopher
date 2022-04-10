/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:13:59 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/10 17:22:21 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(t_info *info, t_philo *philo)
{
	info->is_end = 1;
	free_info(info);
	if (philo != 0)
		free(philo);
}

void	free_info(t_info *info)
{
	int	i;

	i = -1;
	all_mutex_destroy(info);
	free(info->t_id);
	free(info->fork);
}

void	all_mutex_destroy(t_info *info)
{
	int	i;

	i = -1;
	if (info->m != 0)
	{
		while (++i <= info->num_philo)
		{
			pthread_mutex_unlock(&(info->m[i]));
			pthread_mutex_destroy(&(info->m[i]));
		}
		free(info->m);
	}
}
