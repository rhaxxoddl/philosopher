/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:52:43 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/29 18:15:52 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <errno.h>

void	*print_thread(void *num)
{
	int	i = -1;
	while (++i < 5)
	{
		printf("I'm No.%d Thread %d\n", *(int *)num, i);
		sleep(1);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	t_info	info;
	pthread_t **t_id;

	t_id = 0;
	if (parsing(argc, argv, &info, t_id) == 0)
	{
		perror("ERROR\nImproper parameter");
		return (0);
	}
	// if (init_mutex(&arg) == 0)
	// 	p_error("Error\n: Failed init_mutex", &arg);
	create_philo(&info, t_id);
	while (info.num_philo > 0)
	{
		usleep(1);
	}
	return (0);
}
