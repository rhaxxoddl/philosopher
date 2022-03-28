/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:13:59 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/28 10:21:56 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_error(char *error_message, t_philo_arg *arg)
{
	free_all(arg);
	printf("%s\n", error_message);
	exit(1);
}

void	free_all(t_philo_arg *arg)
{
	int	i;

	i = -1;
	if (arg->t_pid != 0)
		free(arg->t_pid);
	// if (arg->fork != 0)
	// 	free(arg->fork);
	if (arg->m != 0)
	{
		// while (arg->m[++i] != 0)
		// {
		// 	write(2, "2\n", 2);
		// 	pthread_mutex_destroy(&(arg->m[i]));
		// }
		// free(arg->m);
	}
}
