/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:13:59 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/02 17:27:23 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_error(char *error_message, t_info *info, t_philo *philo)
{
	free_info(info);
	free_t_philo(philo);
	printf("%s\n", error_message);
	exit(1);
}

void	free_info(t_info *info)
{
	int	i;

	i = -1;
	free(info->t_id);
	if (info->m != 0)
	{
		while (++i <= info->num_philo)
			pthread_mutex_destroy(&(info->m[i]));
		free(info->m);
	}
}

int	free_t_philo(t_philo *philo)
{
	if (philo != 0)
		free(philo);
	return (0);
}
