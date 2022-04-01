/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:52:43 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/01 17:08:42 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	t_info	info;

	if (parsing(argc, argv, &info) == 0)
	{
		perror("ERROR\nImproper parameter");
		return (0);
	}
	create_philo(&info);
	free_info(&info);
	return (0);
}
