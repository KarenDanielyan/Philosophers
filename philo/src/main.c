/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:10:29 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/29 20:11:55 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args	args;
	t_data	data;

	get_time();
	args = parse(ac, av);
	new_data(&data, args);
	launch(&data);
	printf("Great success\n");
	return (0);
}
