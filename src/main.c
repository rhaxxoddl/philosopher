/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:52:43 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/27 18:52:49 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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
	// int	status;
	// int	i;
	// int	num[4] = {1, 2, 3, 4};
	// pthread_t	t_id[4];
	t_arg	arg;
	
	if (parsing(argc, argv, &arg) == 0)
	{
		perror("ERROR\nImproper parameter");
		return (0);
	}
	printf("num_philo : %d\n", arg.num_philo);
	printf("time_die : %d\n", arg.time_die);
	printf("time_eat : %d\n", arg.time_eat);
	printf("time_sleep : %d\n", arg.time_sleep);
	if (argc == 6)
		printf("num_eat : %d\n", arg.num_eat);

	// status = 0;
	// i = -1;

	// while (++i < 4)
	// {
	// 	t_id[i] = pthread_self();
	// 	// printf("t_id : %d\n", i);
	// 	status = pthread_create(&t_id[i], NULL, print_thread, (void *)&num[i]);
	// // write(1, "1\n", 2);
	// 	if (status < 0)
	// 		{
	// 			perror("Failed create thread : ");
	// 			exit(0);
	// 		}
	// }
	// pthread_join(t_id[0], (void **)&status);
	// pthread_join(t_id[1], (void **)&status);
	// pthread_join(t_id[2], (void **)&status);
	// pthread_join(t_id[3], (void **)&status);
	// for (int j = 0; j < 4; j++)
	// {
	// 	pthread_join(t_id[i], (void **)&status);
	// }
	return (0);
}
