/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:35:28 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/30 11:06:54 by sanjeon          ###   ########.fr       */
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
	int				del_philo;
	pthread_mutex_t	**m;
	pthread_t		**t_id;
}				t_info;

typedef struct s_philo
{
	int				philo_seq;
	int				num_eat;
	t_info			*info;
}				t_philo;

// create.c
int		create_philo(t_info *info);
t_philo	**init_philo(t_info *info);
// error.c
void	p_error(char *error_message, t_info *info);
void	free_all(t_info *info);
int		free_t_id(pthread_t **t_id);
int		free_t_philo(t_philo **philo);
// parsing.c
int		parsing(int argc, char *argv[], t_info *info);
pthread_t	**init_t_id(int num_philo);
int		check_isnum(int argc, char *argv[]);
void	init_info(int argc, t_info *info);
int		init_mutex(t_info *info);
int		init_sam_mutex(t_info *info);
// philo.c
void	*even_philo(void *a);
void	*odd_philo(void *a);
void	add_fork(t_info *info, int num);
void	print_info(t_philo *philo);
#endif
