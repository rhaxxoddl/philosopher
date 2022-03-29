/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:35:28 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/29 18:14:15 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_info
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	int				fork;
	pthread_mutex_t	**m;
}				t_info;

typedef struct s_philo
{
	int				philo_seq;
	int				num_eat;
	t_info			*info;
}				t_philo;

// create.c
void	create_philo(t_philo_arg *arg, pthread_t **t_id);
t_philo	*init_philo(t_info *info, int seq);
// error.c
void	p_error(char *error_message, t_info *info);
void	free_all(t_info *info);
// parsing.c
int		parsing(int argc, char *argv[], t_info *info, pthread_t *t_id);
int		check_isnum(int argc, char *argv[]);
void	init_arg(int argc, t_info *info);
int		init_mutex(t_info *info);
int		init_sam_mutex(t_info *info);
// philo.c
void	*even_philo(void *a);
void	*odd_philo(void *a);
void	add_fork(t_philo_arg *arg, int num);
#endif
