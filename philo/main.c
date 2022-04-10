/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:52:43 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/10 17:16:45 by sanjeon          ###   ########.fr       */
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
	// int		state;

	info = (t_info *)ft_calloc(1, sizeof(t_info));
	if (parsing(argc, argv, info) == 0)
	{
		perror("ERROR\nImproper parameter");
		return (0);
	}
	philo = create_philo(info);
	if (start_philo(info, philo) == 0)
		ft_exit(info, philo);
	i = 0;
	// state = 0;
	while (++i <= info->num_philo)
		pthread_join(info->t_id[i], NULL);
	ft_exit(info, philo);
	return (0);
}
