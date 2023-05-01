/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:32:43 by kdaniely          #+#    #+#             */
/*   Updated: 2023/05/01 19:04:54 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (*(s + i))
			i ++;
	}
	return (i);
}

static int	is_number(const char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

int	check_number(const char *s)
{
	if (!is_number(s))
		return (0);
	if (*s == '+' || *s == '-')
		s ++;
	while (*s == '0')
		s ++;
	if (ft_strlen(s) > 11)
		return (0);
	return (1);
}
