/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:05:02 by mpascual          #+#    #+#             */
/*   Updated: 2023/06/29 15:49:52 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* ARGS
number_of_philosophers
time_to_die
time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/

int main(int argc, char **argv)
{
	t_rules rules;

	if (argc > 6 || argc < 5)
		ft_putstr("Error\n Wrong number of arguments\n");
	rules.n_philos = ft_atoi(argv[1]);
	rules.ttdie = ft_atoi(argv[2]);
	rules.tteat = ft_atoi(argv[3]);
	rules.ttsleep = ft_atoi(argv[4]);
	if (argc == 6)
		rules.ntimes_must_eat = ft_atoi(argv[5]);
	
	return (0);
}