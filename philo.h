/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:03:37 by mpascual          #+#    #+#             */
/*   Updated: 2023/06/30 10:52:12 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define bool	_Bool
# define true	1
# define false	0

typedef struct s_philo
{
	int 		id;
	int			right_fork;
	int			left_fork;
	int			n_meals;
	long long	hungry_time;
}		t_philo;


typedef struct s_rules
{
	int 			n_philos;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				required_meals;
	bool			anyone_dead;
	bool			all_eated;
	long long		start;
	pthread_mutex_t	forks[250];
	pthread_mutex_t	print;
	t_philo			philos[250];

}		t_rules;

/* from messages.c */
void	print_action(t_rules *rules, int n_philo, char *message);
/* from utils.c */
int		ft_atoi(const char *str);

#endif