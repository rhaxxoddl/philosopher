/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:35:28 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/11 10:26:51 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

enum	e_state
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE,
};

typedef struct s_info
{
	long			start_time;
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				req_eat;
	int				*fork;
	int				is_end;
	pthread_mutex_t	*m;
	pthread_t		*t_id;
}				t_info;

typedef struct s_philo
{
	int				philo_seq;
	int				num_eat;
	long			last_eat;
	t_info			*info;
}				t_philo;

// action.c
void		*routine(void *a);
int			odd_eat(t_philo *philo);
int			even_eat(t_philo *philo);
void		sleep_and_think(t_philo *philo);

// error.c
int			ft_exit(t_info *info, t_philo *philo);
void		free_info(t_info *info);
int			free_t_id(pthread_t **t_id);
void		all_mutex_destroy(t_info *info);

// fork.c
int			take_fork_l(t_philo *philo);
int			take_fork_r(t_philo *philo);
int			drop_fork_l(t_philo *philo);
int			drop_fork_r(t_philo *philo);

// libft.c
int			ft_atoi(const char *nptr);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);

// parsing.c
int			parsing(int argc, char *argv[], t_info *info);
pthread_t	*init_t_id(int num_philo);
void		init_info(int argc, t_info *info);
int			init_mutex(t_info *info);

// philo.c
void		start_philo(t_info *info, t_philo *philo);
t_philo		*create_philo(t_info	*info);
t_philo		*init_philo(t_info *info);

// util.c
long		get_time(void);
int			check_isnum(int argc, char *argv[]);
void		ft_usleep(useconds_t t);
void		print_state(t_philo *philo, int state);
#endif
