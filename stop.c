/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:20:37 by mpascual          #+#    #+#             */
/*   Updated: 2023/07/26 11:31:50 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dead(t_philo *phil)
{
	bool	is_alive;

	pthread_mutex_lock(&(phil->args->dead_m));
	is_alive = phil->args->is_dead;
	pthread_mutex_unlock(&(phil->args->dead_m));
	return (is_alive);
}

int	stop_threads(t_philo *philo)
{
	pthread_mutex_lock(&(philo->args->dead_m));
	philo->args->is_dead = true;
	pthread_mutex_unlock(&(philo->args->dead_m));
	return (1);
}

int	check_philo_death(t_philo *philo, long cur_time)
{
	bool	dead;
	int		last_meal;

	dead = false;
	pthread_mutex_lock(&(philo->last_meal_m));
	last_meal = cur_time - philo->last_eaten;
	pthread_mutex_unlock(&(philo->last_meal_m));
	if (last_meal > philo->args->ttdie)
	{
		pthread_mutex_lock(&(philo->args->print_m));
		pthread_mutex_lock(&(philo->args->dead_m));
		philo->args->is_dead = true;
		pthread_mutex_unlock(&(philo->args->dead_m));
		printf("%09ld %d died\n", cur_time, philo->position);
		pthread_mutex_unlock(&(philo->args->print_m));
		dead = true;
	}
	return (dead);
}

void	*death_check(void *arg)
/*
	Keep checking constantly if any philosopher has died
	This function should be executed in a separate thread
*/
{
	t_args	*args;
	t_philo		**philos;
	long		cur_time;
	int			i;

	philos = (t_philo **)arg;
	args = philos[0]->args;
	while (1)
	{
		i = 0;
		cur_time = current_time() - args->start_time;
		while (i < args->n_philos)
		{
			if (check_philo_death(&(*philos)[i], cur_time))
				return (NULL);
			i++;
		}
		custom_usleep(1);
	}
	return (NULL);
}