/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:21:08 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/22 21:31:34 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

# define M2BIG "Argument bigger than INT_MAX.\n"
# define MNAI "Non-Integer Argument\n"
# define M2BIG_LEN 30
# define MNAI_LEN 21

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

static t_args	fill_args(long *arr, int len)
{
	t_args	args;
	
	args.philo_num = (int)arr[0];
	args.time_to_die = (int)arr[1];
	args.time_to_eat = (int)arr[2];
	args.time_to_sleep = (int)arr[3];
	if (len == 5)
		args.must_eat_count = (int)arr[4];
	else
		args.must_eat_count = -1;
	return (args);
}

t_args	parse(int ac, char **av)
{
	int		i;
	long	*arr;

	arr = NULL;
	if (ac == 5 || ac == 6)
	{
		arr = (long *)malloc((ac - 1) * sizeof(long));
		i = 1;
		while (i < ac)
		{
			if (!is_number(av[i]))
			{
				write(STDERR_FILENO, MNAI, MNAI_LEN);
				exit(EXIT_FAILURE);
			}
			arr[i] = ft_atol(av[i]);
			if (check_number(av[i]) || arr[i] < 0 || arr[i] > INT32_MAX)
			{
				write(STDERR_FILENO, M2BIG, M2BIG_LEN);
				exit(EXIT_FAILURE);
			}
			i ++;
		}
	}
	return (fill_args(arr, (ac - 1)));
}
