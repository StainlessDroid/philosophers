/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:03:37 by mpascual          #+#    #+#             */
/*   Updated: 2023/06/29 11:53:50 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <time.h>

typedef struct s_rules
{
	int n_philos;
	int	ttdie;
	int	tteat;
	int	ttsleep;
	int	ntimes_must_eat;
}		t_rules;


/* from messages.c */
void	take_fork(int time, int philo);
void	eat(int time, int philo);
void	sleep(int time, int philo);
void	think(int time, int philo);
void	die(int time, int philo);
/* from utils.c */
int		ft_putchar(char c);
int		ft_putstr(const char *str);
int		ft_atoi(const char *str);
void	ft_putnbr(int nb);

#endif