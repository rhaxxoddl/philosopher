/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:55:41 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/27 22:59:31 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo(t_arg *arg)
{
	int	status;
	int	i;

	status = 0;
	i = -1;
	arg->t_pid = ft_calloc(arg->num_philo + 1, sizeof(pthread_t));
	if (arg->t_pid == 0)
		p_error("Error\n: Failed allocate t_pid", arg);
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

