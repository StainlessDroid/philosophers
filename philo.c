/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:05:02 by mpascual          #+#    #+#             */
/*   Updated: 2023/07/25 17:04:39 by mpascual         ###   ########.fr       */
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
	else if (rules->required_meals < 0)
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
	rules.anyone_dead = false;
	rules.all_eated = false;
	if (argc == 6)
		rules.required_meals = ft_atoi(argv[5]);
	else
		rules.required_meals = 0;
	return (rules);	
}

int	create_philos(t_rules *rules)
{
	int i;

	i = 0;
	while (i < rules->n_philos)
	{
		rules->philos[i].id = i;
		rules->philos[i].right_fork = i;
		rules->philos[i].left_fork = i % rules->n_philos;
		i++;
	}
	return (0);
}

void	*thread_routine(void *data)
{
	printf("inside thread[]\n");
	if (data != NULL)
		printf("function data is not NULL\n");
	return (NULL);
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
		return(printf("Error\nWrong number of arguments\n"));
	rules = get_rules(argc, argv);
	if (rules.n_philos < 0 || rules.ttdie < 0 || rules.tteat < 0
		|| rules.ttsleep < 0 || rules.required_meals < 0)
		return(printf("Error\nFucked up arguments\n"));
	if (rules.n_philos > 250)
		return(printf("Too many philosphers, let them starve!\n"));
	return (0);
}