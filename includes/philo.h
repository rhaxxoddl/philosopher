/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:35:28 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/30 18:40:19 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_info
{
	long			start_time;
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				req_eat;
	int				*fork;
	int				del_philo;
	pthread_mutex_t	**m;
	pthread_t		**t_id;
}				t_info;

typedef struct s_philo
{
	int				philo_seq;
	int				num_eat;
	// int				last_eat;
	t_info			*info;
}				t_philo;

// action.c
int		routine(t_info *info, int seq);
int		even_eat(t_info *info, int seq);
int		odd_eat(t_info *info, int seq);
void	sleep_and_think(t_info *info, int seq);
// create.c
int		create_philo(t_info *info);
t_philo	**init_philo(t_info *info);
// error.c
void	p_error(char *error_message, t_info *info);
void	free_all(t_info *info);
int		free_t_id(pthread_t **t_id);
int		free_t_philo(t_philo **philo);
// fork.c
int		take_fork_l(t_info *info, int seq);
int		take_fork_r(t_info *info, int seq);
int		drop_fork_l(t_info *info, int seq);
int		drop_fork_r(t_info *info, int seq);
// parsing.c
int		parsing(int argc, char *argv[], t_info *info);
long	get_time();
pthread_t	**init_t_id(int num_philo);
int		check_isnum(int argc, char *argv[]);
void	init_info(int argc, t_info *info);
int		init_mutex(t_info *info);
// philo.c
void	*even_philo(void *a);
void	*odd_philo(void *a);
void	print_info(t_philo *philo);
#endif
