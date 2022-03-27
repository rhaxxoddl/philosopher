/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:52:43 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/27 23:01:15 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <errno.h>

int				g_fork = 0;
pthread_mutex_t **g_m = 0;

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
	// int	i;
	t_arg	arg;

	if (parsing(argc, argv, &arg) == 0)
	{
		perror("ERROR\nImproper parameter");
		return (0);
	}
	if (init_mutex(arg.num_eat) == 0)
		p_error("Error\n: Failed init_mutex", &arg);
	create_philo(&arg);
	return (0);
}
