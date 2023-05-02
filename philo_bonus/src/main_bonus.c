/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:10:29 by kdaniely          #+#    #+#             */
/*   Updated: 2023/05/02 15:20:22 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_args	args;
	t_data	data;

	data.start_t = 0;
	data.start_t = get_time(&data);
	args = parse(ac, av);
	new_data(&data, args);
	launch(&data);
	printf("Great success\n");
	return (0);
}
