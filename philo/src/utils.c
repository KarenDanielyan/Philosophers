/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:47:39 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/28 21:05:09 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define OFFSET '0'

void	get_time(t_time *t)
{
	static int		exec_c;
	static t_time	init;

	if (exec_c == 0 || !t)
		gettimeofday(&init, NULL);
	gettimeofday(t, NULL);
	if (t)
	{
		t->tv_sec = t->tv_sec - init.tv_sec;
		t->tv_usec = t->tv_usec - init.tv_usec;
	}
	exec_c ++;
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
