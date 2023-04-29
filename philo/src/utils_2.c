/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:57:01 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/29 22:20:57 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*pick_msg(int stat)
{
	if (stat == DEAD)
		return (DEAD_MSG);
	if (stat == EATING)
		return (EATING_MSG);
	if (stat == PICKING)
		return (FORK_MSG);
	if (stat == SLEEPING)
		return (SLEEPING_MSG);
	if (stat == THINKING)
		return (THINKING_MSG);
	return (NULL);
}
/**
 * @brief	Prints the status of given philosopher
 * 			in STDOUT
 * 
 * @param data	Data structure that describe simulation
 * 				status.
 * @param code	Status code sent by the philosopher
 */
void	post(t_data *data, int code)
{
	long	t;

	t = get_time(0);
	if (!is_ended(data))
	{
		pthread_mutex_lock(&(data->p_mux));
		printf("%li %d %s\n", t, (code / 10), pick_msg(code % 10));
		pthread_mutex_unlock(&(data->p_mux));
	}
}