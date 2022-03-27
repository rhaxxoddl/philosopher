/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:19:53 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/27 23:02:44 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int argc, char *argv[], t_arg *arg)
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

void	init_arg(int argc, t_arg *arg)
{
	arg->num_philo = 0;
	arg->time_die = 0;
	arg->time_eat = 0;
	arg->time_sleep = 0;
	if (argc == 6)
		arg->num_eat = 0;
}

int		init_mutex(int num_philo)
{
	int	i;

	i = -1;
	/*
	이미 할당된 곳에 할당한다고 오류남. mutex 하나로 여러 개의 변수를 동기화할 수 있는가?
	*/
	g_m = ft_calloc(num_philo, sizeof(pthread_mutex_t));
	if (g_m != 0)
		return (0);
	while (++i < num_philo)
	{
		if (pthread_mutex_init(g_m[i], NULL) == 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(g_m[i]);
			return (0);
		}
	}
	return (1);
}
