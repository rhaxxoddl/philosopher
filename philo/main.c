/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:52:43 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/10 19:10:33 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <errno.h>

int	main(int argc, char *argv[])
{
	t_info	*info;
	t_philo	*philo;
	int		i;

	info = 0;
	info = (t_info *)ft_calloc(1, sizeof(t_info));
	if (info == 0)
		return (0);
	if (parsing(argc, argv, info) == 0)
		return (ft_exit(info, 0));
	philo = 0;
	philo = create_philo(info);
	if (philo == 0)
		return (ft_exit(info, 0));
	start_philo(info, philo);
	i = 0;
	while (++i <= info->num_philo)
		pthread_join(info->t_id[i], NULL);
	return (ft_exit(info, philo));
}
