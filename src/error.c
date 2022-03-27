/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:13:59 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/27 22:56:12 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_error(char *error_message, t_arg *arg)
{
	free_all(arg);
	printf("%s\n", error_message);
	exit(1);
}

void	free_all(t_arg *arg)
{
	int	i;

	i = -1;
	if (arg->t_pid != 0)
		free(arg->t_pid);
	// if (g_fork != 0)
	// 	free(g_fork);
	if (g_m != 0)
	{
		while (++i < arg->num_philo)
			pthread_mutex_destroy(g_m[i]);
		free(g_m);
	}
}
