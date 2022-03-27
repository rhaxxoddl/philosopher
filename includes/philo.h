/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:35:28 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/27 22:55:35 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

extern int				g_fork;
extern pthread_mutex_t	**g_m;

typedef struct s_arg{
	int	num_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	num_eat;
	pthread_t *t_pid;
}				t_arg;
// create.c
void	create_philo(t_arg *arg);
// error.c
void	p_error(char *error_message, t_arg *arg);
void	free_all(t_arg *arg);
// parsing.c
int		parsing(int argc, char *argv[], t_arg *arg);
int		check_isnum(int argc, char *argv[]);
void	init_arg(int argc, t_arg *arg);
int		init_mutex(int num_philo);
// philo.c
void	*even_philo(void *a);
void	*odd_philo(void *a);
#endif
