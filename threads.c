/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:38:01 by mpascual          #+#    #+#             */
/*   Updated: 2023/07/26 11:53:49 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_philo **philos, t_args *args)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < args->n_philos)
	{
		if (pthread_join((*philos)[i].thread_id, NULL))
			ret = 1;
		i++;
	}
	return (ret);
}

int	start_threads(t_philo **philos, t_args *args)
/*
	creates philosopher's threads and death check thread
*/
{
	int	i;

	i = 0;
	args->start_time = current_time();
	while (i < args->n_philos)
	{
		if (pthread_create(&((*philos)[i].thread_id), NULL,
			philo_routine, &((*philos)[i])))
			return (0);
		i++;
	}
	if (pthread_create(&(args->death_thread_id), NULL,
			death_check, philos))
		return (0);
	return (1);
}

void	create_philo(t_philo *philo, t_args *args, t_fork **forks, int i)
/*
	Inicializa las variables del filosofo y
	asigna los tenedores correspondientes
*/
{
	philo->args = args;
	philo->position = i;
	philo->last_eaten = 0;
	philo->meal_count = 0;
	philo->right_fork = &((*forks)[i]);
	philo->has_r_fork = false;
	philo->has_l_fork = false;
	if (i == args->n_philos - 1)
		philo->left_fork = &((*forks)[0]);
	else
		philo->left_fork = &((*forks)[i + 1]);
	philo->left_fork->in_use = true;
	pthread_mutex_init(&(philo->last_meal_m), NULL);
	pthread_mutex_init(&(philo->left_fork->lock), NULL);
}

int	create_all_philos(t_philo **philos, t_args *args, t_fork **forks)
/*
	Aloja memoria para todos los filosofos y tenedores
	y inicializa los filosofos
*/
{
	int	i;

	i = 0;
	*philos = malloc(sizeof(t_philo) * args->n_philos);
	if (!(*philos))
		return (1);
	*forks = malloc(sizeof(t_fork) * args->n_philos);
	if (!(*forks))
	{
		free(*philos);
		return (1);
	}
	args->start_time = current_time();
	while (i < args->n_philos)
	{
		create_philo(&((*philos)[i]), args, forks, i);
		i++;
	}
	if (start_threads(philos, args))
		return (1);
	return (0);
}
