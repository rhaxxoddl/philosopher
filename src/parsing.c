/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:19:53 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/29 18:16:26 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int argc, char *argv[], t_info *info, pthread_t **t_id)
{
	if (argc < 5 || argc > 6 || check_isnum(argc, argv) == 0)
		return (0);
	init_arg(argc, info);
	info->num_philo = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->num_eat = ft_atoi(argv[5]);
	t_id = (pthread_t **)ft_calloc(info->num_philo + 1, sizeof(pthread_t));
	if (*t_id == 0)
		p_error("Error\n: Failed allocate t_pid", info);
	if (init_sam_mutex(info) == 0)
		p_error("Error\n: Failed init mutex", info);
	return (1);
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

void	init_arg(int argc, t_info *info)
{
	info->num_philo = 0;
	info->time_die = 0;
	info->time_eat = 0;
	info->time_sleep = 0;
	if (argc == 6)
		info->num_eat = 0;
	info->m = 0;
	info->fork = 0;
}

int		init_sam_mutex(t_info *info)
{
	int	status = 0;
	// arg->m = (pthread_mutex_t **)ft_calloc(arg->num_philo, sizeof(pthread_mutex_t *));
	info->m = (pthread_mutex_t **)ft_calloc(1, sizeof(pthread_mutex_t *));
	if (info->m == 0)
		return (0);
	info->m[0] = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	if (info->m[0] == 0)
		return (0);
	// arg->m[1] = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	// if (arg->m[1] == 0)
		// free(arg->m[0]);
	if ((status = pthread_mutex_init(info->m[0], NULL)) != 0)
		return (-1);
	// if ((status = pthread_mutex_init(arg->m[1], NULL)) != 0)
	// 	return (-1);
	return (1);
}

int		init_mutex(t_info *info)
{
	int	status = 0;
	int	i;

	i = -1;
	info->m = (pthread_mutex_t **)ft_calloc(info->num_philo, sizeof(pthread_mutex_t *));
	if (info->m == 0)
		return (0);
	while (++i < info->num_philo)
	{
		info->m[i] = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
		if (info->m[i] == 0)
		{
			while (--i > 0)
				free(info->m[i]);
		}
	}
	while (++i < info->num_philo)
	{
		if ((status = pthread_mutex_init(info->m[i], NULL)) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(info->m[i]);
			return (0);
		}
	}
	return (1);
}
