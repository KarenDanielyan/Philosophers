/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:10:29 by kdaniely          #+#    #+#             */
/*   Updated: 2023/05/01 18:59:17 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args	args;
	t_data	data;

	get_time(42);
	args = parse(ac, av);
	new_data(&data, args);
	launch(&data);
	printf("Great success\n");
	return (0);
}
