/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:52:43 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/07 09:36:33 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <errno.h>

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philo;

	if (parsing(argc, argv, &info) == 0)
	{
		perror("ERROR\nImproper parameter");
		return (0);
	}
	philo = create_philo(&info);
	if (start_philo(&info, philo) == 0)
		p_error("Error\n:Failed start_philo()!", &info, philo);
	free_t_philo(philo);
	free_info(&info);
	return (0);
}
