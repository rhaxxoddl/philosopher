/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:03:14 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/10 16:38:42 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	return ((tv.tv_usec / 1000) + (tv.tv_sec * 1000));
}

int	check_isnum(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (++j < (int)ft_strlen(argv[i]))
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
		}
	}
	return (1);
}

void	ft_usleep(useconds_t t)
{
	long	start_sleep;

	start_sleep = get_time();
	while (get_time() - start_sleep < t)
	{
		usleep(300);
	}
}

void	print_state(t_philo *philo, int state)
{
	if (philo->info->is_end == 0 && pthread_mutex_lock(&(philo->info->m[0])))
		return ;
	if (philo->info->is_end == 0 && state == 0)
		printf("%ldms %d has taken a fork\n",
			get_time() - philo->info->start_time, philo->philo_seq);
	else if (philo->info->is_end == 0 && state == 1)
	{
		philo->last_eat = get_time();
		philo->num_eat++;
		printf("%ldms %d is eating\n",
			philo->last_eat - philo->info->start_time, philo->philo_seq);
	}
	else if (philo->info->is_end == 0 && state == 2)
		printf("%ldms %d is sleeping\n",
			get_time() - philo->info->start_time, philo->philo_seq);
	else if (philo->info->is_end == 0 && state == 3)
		printf("%ldms %d is thinking\n",
			get_time() - philo->info->start_time, philo->philo_seq);
	else if (philo->info->is_end == 0 && state == 4)
	{
		philo->info->is_end = 1;
		printf("%ldms %d is died\n",
			get_time() - philo->info->start_time, philo->philo_seq);
		return ;
	}
	pthread_mutex_unlock(&(philo->info->m[0]));
}
