/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:13:59 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/30 10:21:56 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_error(char *error_message, t_info *info)
{
	free_all(info);
	printf("%s\n", error_message);
	exit(1);
}

void	free_all(t_info *info)
{
	int	i;

	i = -1;
	// if (info->t_id != 0)
	// 	free(info->t_id);
	// if (arg->fork != 0)
	// 	free(arg->fork);
	if (info->m != 0)
	{
		// while (arg->m[++i] != 0)
		// {
		// 	write(2, "2\n", 2);
		// 	pthread_mutex_destroy(&(arg->m[i]));
		// }
		// free(arg->m);
	}
}

int	free_t_philo(t_philo **philo)
{
	int	i;

	if (philo != 0)
	{
		i = -1;
		while (philo[++i] != 0)
			free(philo[i]);
		free(philo);
	}
	return (0);
}

int	free_t_id(pthread_t **t_id)
{
	int	i;

	if (t_id != 0)
	{
		i = -1;
		while (t_id[++i] != 0)
			free(t_id[i]);
		free(t_id);
	}
	return (0);
}
