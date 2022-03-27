/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:51:39 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/27 22:47:41 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*even_philo(void *a)
{
	int	num;
	int	i;

	num = *((int *)a);
	i = -1;
	while (++i < 5)
	{
		pthread_mutex_lock(g_m[num]);
		printf("I'm evne %d\nI'm get %dfork!\n", num, g_fork);
		g_fork++;
		pthread_mutex_unlock(g_m[num]);
	}
	return (0);
}

void	*odd_philo(void *a)
{
	int	num;
	int	i;

	num = *((int *)a);
	i = -1;
	while (++i < 5)
	{
		pthread_mutex_lock(g_m[num]);
		printf("I'm odd %d\nI'm get %dfork!\n", num, g_fork);
		g_fork++;
		pthread_mutex_unlock(g_m[num]);
	}
	return (0);
}
