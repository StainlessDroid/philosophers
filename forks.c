/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 00:47:59 by mpascual          #+#    #+#             */
/*   Updated: 2023/07/26 11:19:55 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(char fork_name, t_philo *philo)
{
	bool	*taken;
	t_fork	*fork;

	if (!is_dead(philo))
	{
		taken = &(philo->has_r_fork);
		fork = philo->right_fork;
		if (fork_name == 'l')
		{
			taken = &(philo->has_l_fork);
			fork = philo->left_fork;
		}
		pthread_mutex_lock(&(fork->lock));
		if (!(*taken) && !fork->in_use)
		{
			*taken = true;
			fork->in_use = true;
			pthread_mutex_unlock(&(fork->lock));
			print_action(philo->args, philo->position, "has taken a fork");
		}
		else
			pthread_mutex_unlock(&(fork->lock));
	}
}

void	release_fork(char fork_name, t_philo *philo)
{
	bool		*taken;
	t_fork	*fork;

	taken = &(philo->has_r_fork);
	fork = philo->right_fork;
	if (fork_name == 'l')
	{
		taken = &(philo->has_l_fork);
		fork = philo->left_fork;
	}
	pthread_mutex_lock(&(fork->lock));
	*taken = 0;
	fork->in_use = 0;
	pthread_mutex_unlock(&(fork->lock));
}

void	release_both_forks(t_philo *philo)
{
	release_fork('r', philo);
	release_fork('l', philo);
	print_action(philo->args, philo->position, "is sleeping");
	custom_usleep(philo->args->ttsleep);
}