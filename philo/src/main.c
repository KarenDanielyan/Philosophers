/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:10:29 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/27 16:20:36 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_time(t_time *t)
{
	static int		exec_c;
	static t_time	init;

	if (exec_c == 0)
		gettimeofday(&init, NULL);
	gettimeofday(t, NULL);
	if (t)
	{
		t->tv_sec = t->tv_sec - init.tv_sec;
		t->tv_usec = t->tv_usec - init.tv_usec;
	}
	exec_c ++;
}

int	main(int ac, char **av)
{
	t_args	args;
	t_data	data;

	get_time(NULL);
	args = parse(ac, av);
	new_data(&data, args);
	printf("Great success\n");
	return (0);
}