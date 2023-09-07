/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:55:26 by mpascual          #+#    #+#             */
/*   Updated: 2023/07/26 14:12:09 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	custom_usleep(long int time)
{
	long int	start_time;

	start_time = current_time();
	while (current_time() - start_time < time)
		usleep(100);
}

long long	current_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	print_action(t_args *args, int n_philo, char *message)
/*
	REQUIERES MUTEX!
	Print the different actions the philosophers are doing
	with the given message
*/
{
	pthread_mutex_lock(&(args->print_m));
	if (args->is_dead == 0)
		printf("[%09lld] %i %s", current_time() - args->start_time,
			n_philo, message);
	pthread_mutex_unlock(&(args->print_m));
}

t_args	get_args(int argc, char **argv)
/*
	Only stores the arguments
	Basic parsing is done in the caller function (main)
*/
{
	t_args	args;

	args.n_philos = ft_atoi(argv[1]);
	args.ttdie = ft_atoi(argv[2]);
	args.tteat = ft_atoi(argv[3]);
	args.ttsleep = ft_atoi(argv[4]);
	args.is_dead = 0;
	if (argc == 6)
		args.max_meals = ft_atoi(argv[5]);
	else
		args.max_meals = 0;
	return (args);
}

int	ft_atoi(const char *str)
/*
	Modified to return -1 if the number is not valid
	This is to ease paring in the main function
*/
{
	long int	n;
	int			sign;

	n = 0;
	sign = 1;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '-')
		return (-1);
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			n = n * 10 + (*str++ - '0');
		else
			return (-1);
	}
	return ((int)(n * sign));
}
