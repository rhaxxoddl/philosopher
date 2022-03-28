/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:51:39 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/28 11:39:59 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*even_philo(void *a)
{
	t_philo_arg	*arg;
	int	i;

	arg = a;
	i = -1;
	while (++i < 5)
	{
		printf("arg->m : %p\n", arg->m[arg->philo_seq]);
		if (pthread_mutex_lock(arg->m[arg->philo_seq]) != 0)
			write(1, "no\n", 3);
		printf("I'm evne %d\nI'm get %dfork!\n", arg->philo_seq, arg->fork);
		arg->fork++;
		pthread_mutex_unlock(arg->m[arg->philo_seq]);
	}
	pthread_mutex_lock(arg->m[arg->philo_seq]);
	arg->num_philo--;
	pthread_mutex_unlock(arg->m[arg->philo_seq]);
	return (0);
}

void	*odd_philo(void *a)
{
	t_philo_arg	*arg;
	int	i;

	arg = a;
	i = -1;
	while (++i < 5)
	{
		printf("%p\n", arg->m);
		// pthread_mutex_lock(arg->m[arg->philo_seq]);
		printf("I'm odd %d\nI'm get %dfork!\n", arg->philo_seq, arg->fork);
		arg->fork++;
		// pthread_mutex_unlock(arg->m[arg->philo_seq]);
	}
	// pthread_mutex_lock(arg->m[arg->philo_seq]);
	arg->num_philo--;
	// pthread_mutex_unlock(arg->m[arg->philo_seq]);
	return (0);
}
