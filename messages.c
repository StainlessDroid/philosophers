/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:59:55 by mpascual          #+#    #+#             */
/*   Updated: 2023/06/29 17:07:15 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** Print the different actions the philosophers are doing
** Take a timestamp in miliseconds and the philosophers's number as argument
** Manage exit calls if all philos eat the necessary times or one of them dies
*/

void	take_fork(int time, int philo)
{
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(philo);
	ft_putstr(" has taken a fork\n");
}

void	eating(int time, int philo)
// +1 argument -> times_each_philo_must_eat
{
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(philo);
	ft_putstr(" is eating\n");
}

void	sleeping(int time, int philo)
{
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(philo);
	ft_putstr(" is sleeping\n");
}

void	thinking(int time, int philo)
{
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(philo);
	ft_putstr(" is thinking\n");
}

void	dying(int time, int philo)
{
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(philo);
	ft_putstr(" DIED\n");
}