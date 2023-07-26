/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:03:37 by mpascual          #+#    #+#             */
/*   Updated: 2023/07/26 11:33:56 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define bool	_Bool
# define true	1
# define false	0

typedef struct s_fork
{
	bool			in_use;
	pthread_mutex_t	lock;
}		t_fork;

typedef struct s_args
{
	int 			n_philos;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				max_meals;
	bool			is_dead;
	long int		start_time;
	pthread_mutex_t	print_m;
	pthread_mutex_t	dead_m;
	pthread_t		death_thread_id;

}		t_args;

typedef struct s_philo
{
	pthread_t 		thread_id;
	int				position;
	t_fork			*right_fork;
	t_fork			*left_fork;
	int				meal_count;
	long long		last_eaten;
	bool			has_r_fork;
	bool			has_l_fork;
	pthread_mutex_t	last_meal_m;
	t_args			*args;
}		t_philo;

/* from philo.c */
void	*philo_routine(void *arg);
void	free_mem(t_philo *philos, t_fork *forks);
/* from threads.c */
int		start_threads(t_philo **philos, t_args *args);
int		join_threads(t_philo **philos, t_args *args);
int		create_all_philos(t_philo **philos, t_args *args, t_fork **forks);
/* from utils.c */
void	print_action(t_args *args, int n_philo, char *message);
long long	current_time(void);
void	custom_usleep(long int time);
t_args	get_args(int argc, char **argv);
int		ft_atoi(const char *str);
/* from forks.c */
void	release_fork(char fork_name, t_philo *philo);
void	take_fork(char fork_name, t_philo *philo);
void	release_both_forks(t_philo *philo);
/* from stop.c */
bool	is_dead(t_philo *phil);
int		stop_threads(t_philo *philo);
void	*death_check(void *arg);
#endif