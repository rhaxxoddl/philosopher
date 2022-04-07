/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:03:14 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/07 09:37:39 by sanjeon          ###   ########.fr       */
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
		usleep(100);
	}
}

void	philo_exit(t_info *info)
{
	free_info(info);
	exit(0);
}

void	print_state(t_philo *philo, int state, long current_time)
{
	pthread_mutex_lock(&(philo->info->m[0]));
	long	current_time;

	if (time != 0)
		current_time = time;
	else
		current_time = get_time();
	if (state == 0)
		printf("%ldms %d has taken a fork\n",
			current_time - philo->info->start_time, philo->philo_seq);
	else if (state == 1)
	{
		philo->last_eat = current_time;
		philo->num_eat++;
		printf("%ldms %d is eating\n",
			philo->last_eat - philo->info->start_time, philo->philo_seq);
	}
	else if (state == 2)
		printf("%ldms %d is sleeping\n",
			current_time - philo->info->start_time, philo->philo_seq);
	else if (state == 3)
		printf("%ldms %d is thinking\n",
			current_time - philo->info->start_time, philo->philo_seq);
	else if (state == 4)
	{
		printf("%ldms %d is died\n",
			current_time - philo->info->start_time, philo->philo_seq);
		return ;
	}
	pthread_mutex_unlock(&(philo->info->m[0]));
}
