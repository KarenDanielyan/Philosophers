/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:13:17 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/29 16:23:10 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*	Return Value: 0 on NO and 1 on YES.
*/
int	is_ended(t_data *data)
{
	int	rv;

	pthread_mutex_lock(&data->end_mux);
	rv = data->is_ended;
	pthread_mutex_lock(&data->end_mux);
	return (rv);
}

void	philo(void *p)
{
	t_philo	*philo;

	((t_philo *)p)->last_meal = get_time();
	philo = (t_philo *)p;
	if (philo->numb % 2)
		usleep(1000);
	while (!is_ended(philo->data))
	{
		// TODO: Add what philo should do aka eating and whatever.
	}
}
