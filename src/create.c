/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:55:41 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/28 10:39:46 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo(t_philo_arg *arg)
{
	int	status;
	int	i;

	status = 0;
	i = -1;
	while (++i < arg->num_philo)
	{
		if (i % 2 == 0)
			status = pthread_create(&(arg->t_pid[i]), NULL, even_philo, (void *)&i);
		else
			status = pthread_create(&(arg->t_pid[i]), NULL, odd_philo, (void *)&i);
		if (status < 0)
			p_error("Error\n: Failed create thread", arg);
		if (pthread_detach(arg->t_pid[i]) != 0)
			p_error("Error\n: Failed detach thread", arg);
	}
}

