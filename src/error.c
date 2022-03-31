/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:13:59 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/31 20:42:14 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_error(char *error_message, t_info *info, t_philo **philo)
{
	free_info(*info);
	free_t_philo(philo);
	printf("%s\n", error_message);
	exit(1);
}

void	free_info(t_info info)
{
	int	i;

	i = -1;
	free_t_id(info.t_id);
	if (info.m != 0)
	{
		while (info.m[++i] != 0)
			pthread_mutex_destroy(info.m[i]);
		free(info.m);
	}
}

int	free_t_philo(t_philo **philo)
{
	int	i;

	if (philo != 0)
	{
		i = -1;
		while ((philo)[++i] != 0)
			free((philo)[i]);
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
