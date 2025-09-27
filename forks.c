/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 00:47:59 by mapascua          #+#    #+#             */
/*   Updated: 2025/09/27 09:54:05 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(char fork_name, t_philo *philo)
{
	int		*taken;
	t_fork	*fork;

	taken = &(philo->has_r_fork);
	fork = philo->right_fork;
	if (fork_name == 'l')
	{
		taken = &(philo->has_l_fork);
		fork = philo->left_fork;
	}
	pthread_mutex_lock(&(fork->lock));
	if (*taken == 0 && fork->in_use == 0)
	{
		*taken = 1;
		fork->in_use = 1;
		pthread_mutex_unlock(&(fork->lock));
		print_action(philo->args, philo->position, "has taken a fork\n");
	}
	else
		pthread_mutex_unlock(&(fork->lock));
}

void	release_fork(char fork_name, t_philo *philo)
{
	int		*taken;
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
	print_action(philo->args, philo->position, "is sleeping\n");
	custom_usleep(philo->args->ttsleep);
	print_action(philo->args, philo->position, "is thinking\n");
}
