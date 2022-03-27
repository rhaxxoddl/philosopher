/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:19:53 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/27 18:50:43 by sanjeon          ###   ########.fr       */
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
