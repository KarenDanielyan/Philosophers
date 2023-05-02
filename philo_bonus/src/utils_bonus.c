/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:47:39 by kdaniely          #+#    #+#             */
/*   Updated: 2023/05/02 14:15:37 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

#define OFFSET '0'

long	get_time(int c)
{
	static t_time	init;
	t_time			t;

	if (c == 42)
		gettimeofday(&init, NULL);
	gettimeofday(&t, NULL);
	t.tv_sec = t.tv_sec - init.tv_sec;
	t.tv_usec = t.tv_usec - init.tv_usec;
	return ((long)((t.tv_sec * 1000) + (t.tv_usec / 1000)));
}

static short	is_num(const char *chr)
{
	if (*chr >= '0' && *chr <= '9')
		return (1);
	else
		return (0);
}

static short	is_whitespace(const char *chr)
{
	if ((*chr >= '\b' && *chr <= '\r') || *chr == 32)
		return (1);
	else
		return (0);
}

/*
*	Reference: <stdlib.h>
*
*	Description: ft_atol() converts the inital portion of the string
*	pointed by *str to long.
*
*	Return Value: The converted value or 0 on error.
*/
long	ft_atol(const char *str)
{
	long		num;
	short		sign;
	const char	*c;

	sign = 1;
	c = str;
	while (is_whitespace(c))
		c ++;
	if (*c == '-' || *c == '+')
	{
		if (*c == '-')
			sign = -1;
		c ++;
	}
	num = 0;
	while (*c != '\0')
	{
		if (!is_num(c))
			break ;
		num *= 10;
		num += (int)(*c - OFFSET);
		c++;
	}
	return (sign * num);
}

/**
 * @brief		Sleeps given amount of miliseconds.
 * 
 * @param ms	miliseconds
 * @param data	Simulation data structure.
 */
void	ft_msleep(long ms, t_data *data)
{
	long	init;
	long	elapsed;

	init = get_time(0);
	elapsed = 0;
	while (!is_dead(data))
	{
		elapsed = get_time(0) - init;
		if (elapsed >= ms)
			break ;
		usleep(50);
	}
}
