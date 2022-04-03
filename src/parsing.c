/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:19:53 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/03 12:55:16 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int argc, char *argv[], t_info *info)
{
	if (argc < 5 || argc > 6 || check_isnum(argc, argv) == 0)
		return (0);
	init_info(argc, info);
	info->start_time = get_time();
	if (info->start_time < 0)
		return (0);
	info->num_philo = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->req_eat = ft_atoi(argv[5]);
	else
		info->req_eat = -1;
	info->fork = (int *)ft_calloc((info->num_philo) + 1, sizeof(int));
	if (init_mutex(info) == 0)
		p_error("Error\n: Failed init mutex", info, 0);
	info->t_id = init_t_id(info->num_philo);
	if (info->t_id == 0)
		p_error("Error\n: Failed allocate t_pid", info, 0);
	return (1);
}

pthread_t	*init_t_id(int num_philo)
{
	pthread_t	*t_id;
	int			i;

	t_id = 0;
	i = -1;
	t_id = (pthread_t *)ft_calloc(num_philo + 1, sizeof(pthread_t));
	if (t_id == 0)
		return (0);
	return (t_id);
}

void	init_info(int argc, t_info *info)
{
	info->start_time = 0;
	info->num_philo = 0;
	info->time_die = 0;
	info->time_eat = 0;
	info->time_sleep = 0;
	if (argc == 6)
		info->req_eat = 0;
	info->fork = 0;
	info->m = 0;
	info->t_id = 0;
	info->del_philo = 0;
}

int	init_mutex(t_info *info)
{
	int	status;
	int	i;

	i = -1;
	status = 0;
	info->m = (pthread_mutex_t *)ft_calloc(info->num_philo + 1,
			sizeof(pthread_mutex_t));
	if (info->m == 0)
		return (0);
	while (++i <= info->num_philo)
	{
		status = pthread_mutex_init(&(info->m[i]), NULL);
		if (status != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&(info->m[i]));
			return (0);
		}
	}
	return (1);
}
