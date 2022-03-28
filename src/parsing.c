/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:19:53 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/28 10:31:28 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int argc, char *argv[], t_philo_arg *arg)
{
	if (argc < 5 || argc > 6 || check_isnum(argc, argv) == 0)
		return (0);
	init_arg(argc, arg);
	arg->num_philo = ft_atoi(argv[1]);
	arg->time_die = ft_atoi(argv[2]);
	arg->time_eat = ft_atoi(argv[3]);
	arg->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		arg->num_eat = ft_atoi(argv[5]);
	arg->t_pid = ft_calloc(arg->num_philo + 1, sizeof(pthread_t));
	if (arg->t_pid == 0)
		p_error("Error\n: Failed allocate t_pid", arg);
	if (init_mutex(arg) == 0)
		p_error("Error\n: Failed init mutex", arg);
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

void	init_arg(int argc, t_philo_arg *arg)
{
	arg->philo_seq = 0;
	arg->num_philo = 0;
	arg->time_die = 0;
	arg->time_eat = 0;
	arg->time_sleep = 0;
	if (argc == 6)
		arg->num_eat = 0;
	arg->t_pid = 0;
	arg->m = 0;
	arg->fork = 0;
}

int		init_mutex(t_philo_arg *arg)
{
	int	status = 0;
	int	i;

	i = -1;
	arg->m = (pthread_mutex_t **)ft_calloc(arg->num_philo, sizeof(pthread_mutex_t *));
	if (arg->m == 0)
		return (0);
	while (++i < arg->num_philo)
	{
		arg->m[i] = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
		if (arg->m[i] == 0)
		{
			while (--i > 0)
				free(arg->m[i]);
		}
	}
	while (++i < arg->num_philo)
	{
		if ((status = pthread_mutex_init(arg->m[i], NULL)) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(arg->m[i]);
			return (0);
		}
	}
	return (1);
}
