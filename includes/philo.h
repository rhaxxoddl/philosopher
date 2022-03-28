/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:35:28 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/28 10:24:37 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_philo_arg
{
	int				philo_seq;
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	pthread_t		*t_pid;
	pthread_mutex_t	**m;
	int				fork;
}				t_philo_arg;

// create.c
void	create_philo(t_philo_arg *arg);
// error.c
void	p_error(char *error_message, t_philo_arg *arg);
void	free_all(t_philo_arg *arg);
// parsing.c
int		parsing(int argc, char *argv[], t_philo_arg *arg);
int		check_isnum(int argc, char *argv[]);
void	init_arg(int argc, t_philo_arg *arg);
int		init_mutex(t_philo_arg *arg);
// philo.c
void	*even_philo(void *a);
void	*odd_philo(void *a);
#endif
