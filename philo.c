/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:05:02 by mpascual          #+#    #+#             */
/*   Updated: 2023/07/26 13:20:09 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mem(t_philo *philos, t_fork *forks)
{
	free(philos);
	free(forks);
}

void	*philo_routine(void *arg)
/*
	Put to sleep pairs philos while ods eat
	A mutex is requiered to update last_eaten time since more than one thread
	can call the function at the same time
*/
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->position % 2 != 0)
		custom_usleep(philo->args->tteat);
	while (!is_dead(philo))
	{
		if (philo->meal_count >= philo->args->max_meals
			&& philo->args->max_meals > 0)
			break ;
		take_fork('l', philo);
		if (philo->has_l_fork)
			take_fork('r', philo);
		if (philo->has_r_fork && philo->has_l_fork)
		{
			print_action(philo->args, philo->position, "is eating\n");
			custom_usleep(philo->args->tteat);
			philo->meal_count++;
			pthread_mutex_lock(&(philo->last_meal_m));
			philo->last_eaten = current_time() - philo->args->start_time;
			pthread_mutex_unlock(&(philo->last_meal_m));
			release_both_forks(philo);
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
/* EXPECTED ARGUMENTS:
*	number_of_philosophers
*	time_to_die
*	time_to_eat
*	time_to_sleep
*	[number_of_times_each_philosopher_must_eat]
*/
{
	t_args	args;
	t_philo	*philos;
	t_fork	*forks;

	if (argc > 6 || argc < 5)
		return (printf("Error\nWrong number of arguments\n"));
	args = get_args(argc, argv);
	if (args.n_philos < 0 || args.ttdie < 0 || args.tteat < 0
		|| args.ttsleep < 0 || args.max_meals < 0)
		return (printf("Error\nBad arguments\n"));
	if (create_all_philos(&philos, &args, &forks) != 0)
	{
		stop_threads(&philos[0]);
		return (printf("Error\nCould not create philosophers\n"));
	}
	if (join_threads(&philos, &args) != 0)
	{
		free_mem(philos, forks);
		return (printf("Error\nCould not join threads\n"));
	}
	free_mem(philos, forks);
	return (0);
}
