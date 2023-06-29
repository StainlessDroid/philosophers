/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:05:02 by mpascual          #+#    #+#             */
/*   Updated: 2023/06/29 17:34:48 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_rules(t_rules *rules)
{
	if (rules->n_philos < 0)
		return (1);
	else if (rules->ttdie < 0)
		return (1);
	else if (rules->tteat < 0)
		return (1);
	else if (rules->ttsleep < 0)
		return (1);
	else if (rules->ntimes_must_eat < 0)
		return (1);
	else
		return (0);
}

t_rules	get_rules(int argc, char **argv)
{
	t_rules rules;

	rules.n_philos = ft_atoi(argv[1]);
	rules.ttdie = ft_atoi(argv[2]);
	rules.tteat = ft_atoi(argv[3]);
	rules.ttsleep = ft_atoi(argv[4]);
	if (argc == 6)
		rules.ntimes_must_eat = ft_atoi(argv[5]);
	else
		rules.ntimes_must_eat = 0;
	return (rules);	
}

int main(int argc, char **argv)
/* EXPECTED ARGUMENTS:
*	number_of_philosophers
*	time_to_die
*	time_to_eat
*	time_to_sleep
*	[number_of_times_each_philosopher_must_eat]
*/
{
	t_rules rules;

	if (argc > 6 || argc < 5)
		return(error("Wrong number of arguments\n"));
	rules = get_rules(argc, argv);
	if (rules.n_philos < 0 || rules.ttdie < 0 || rules.tteat < 0
		|| rules.ttsleep < 0 || rules.ntimes_must_eat < 0)
		return(error("Fucked up arguments\n"));
	ft_putstr("Empezamos\n");
	return (0);
}