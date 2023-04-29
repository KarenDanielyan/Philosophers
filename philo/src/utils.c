/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:47:39 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/29 16:21:23 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define OFFSET '0'

long long	get_time(void)
{
	static int		exec_c;
	static t_time	init;
	t_time			t;

	if (exec_c == 0)
		gettimeofday(&init, NULL);
	gettimeofday(&t, NULL);
	t.tv_sec = t.tv_sec - init.tv_sec;
	t.tv_usec = t.tv_usec - init.tv_usec;
	exec_c ++;
	return ((long long)((t.tv_sec * 1000) + (t.tv_sec / 1000)));
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

void	ft_usleep(long long us, t_data *data)
{
	long long	init;
	long long	elapsed;

	init = get_time();
	elapsed = 0;
	while (!is_ended(data))
	{
		elapsed = get_time() - init;
		if (elapsed >= us)
			break ;
		usleep(50);
	}
}
