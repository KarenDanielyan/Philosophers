/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:21:08 by kdaniely          #+#    #+#             */
/*   Updated: 2023/05/01 19:04:55 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

#define MINARG "Invalid Number of Arguments.\n"
#define M2BIG "Argument does not fit inside an int.\n"
#define MNEG "You can't go back in time -_-\n"
#define MPHIL "WDYM Negative Philos???\n"
#define MTHUP "Philos cant throw up!!\n"
#define MNAI "Non-Integer Argument\n"
#define MINARG_LEN 30
#define M2BIG_LEN 37
#define MNEG_LEN 31
#define MNAI_LEN 22
#define MPHIL_LEN 25
#define MTHUP_LEN 23

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
	args.time_to_die = arr[1];
	args.time_to_eat = arr[2];
	args.time_to_sleep = arr[3];
	if (len == 5)
		args.must_eat_count = (int)arr[4];
	else
		args.must_eat_count = -1;
	return (args);
}

static void	pick_err_msg(long *arr, int i, char **av, int ac)
{
	if (!is_number(av[i]))
	{
		write(STDERR_FILENO, MNAI, MNAI_LEN);
		exit(EXIT_FAILURE);
	}
	arr[i - 1] = ft_atol(av[i]);
	if (!check_number(av[i]) || arr[i - 1] > INT32_MAX)
	{
		write(STDERR_FILENO, M2BIG, M2BIG_LEN);
		exit(EXIT_FAILURE);
	}
	if (arr[i - 1] < 0)
	{
		if (i == 1)
			write(STDERR_FILENO, MPHIL, MPHIL_LEN);
		else if (i > 1 && i < ac -1)
			write(STDERR_FILENO, MNEG, MNEG_LEN);
		else
			write(STDERR_FILENO, MTHUP, MTHUP_LEN);
		exit(EXIT_FAILURE);
	}
}

static void	arg_fill(long *arr, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		pick_err_msg(arr, i, av, ac);
		i ++;
	}
}

t_args	parse(int ac, char **av)
{
	long	*arr;
	t_args	args;

	arr = NULL;
	if (ac != 5 && ac != 6)
	{
		write(STDERR_FILENO, MINARG, MINARG_LEN);
		exit(EXIT_FAILURE);
	}
	arr = (long *)malloc((ac - 1) * sizeof(long));
	arg_fill(arr, ac, av);
	args = fill_args(arr, (ac - 1));
	free(arr);
	return (args);
}
