/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:59:55 by mpascual          #+#    #+#             */
/*   Updated: 2023/06/30 10:39:41 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** Print the different actions the philosophers are doing
** Take a timestamp in miliseconds and the philosophers's number as argument
** Manage exit calls if all philos eat the necessary times or one of them dies
*/

long long	current_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	print_action(t_rules *rules, int n_philo, char *message)
{
	pthread_mutex_lock(&rules->print);
	if (rules->anyone_dead == false)
	{
		printf("%lli ", current_time() - rules->start);
		printf("%i ", n_philo); // philospher's ID
		printf("%s", message);
	}
	pthread_mutex_unlock(&rules->print);

}