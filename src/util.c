/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:03:14 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/01 17:02:55 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time()
{
	struct timeval tv;

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

void	philo_exit(t_info *info)
{
	free_info(info);
	exit(0);
}

void	print_state(t_info *info, int seq, int state)
{
	if (state == 0)
		printf("%ld %d has taken a fork\n", get_time() - info->start_time, seq);
	else if (state == 1)
		printf("%ld %d is eating\n", get_time() - info->start_time, seq);
	else if (state == 2)
		printf("%ld %d is sleeping\n", get_time() - info->start_time, seq);
	else if (state == 3)
		printf("%ld %d is thinking\n", get_time() - info->start_time, seq);
	else if (state == 4)
		printf("%ld %d is died\n", get_time() - info->start_time, seq);
}
