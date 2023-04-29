/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:13:17 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/29 19:33:27 by kdaniely         ###   ########.fr       */
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
/**
 * @brief 		Helper function for picking the forks.
 * 
 * @param data	Data structure describing the simulation.
 * @param numb	Philosophers number
 * @param l		His left fork
 * @param r		His right fork
 * 
 * WARNING:		Caller function should handle unlocking of mutexes.
 * 				Otherewise, deadlock is immenent.
 */
static void pick_forks(t_data *data, int numb, pthread_mutex_t *l, pthread_mutex_t *r)
{
	pthread_mutex_lock(l);
	post(data, (numb * 10 + PICKING));
	pthread_mutex_lock(r);
	post(data, (numb * 10 + PICKING));
}

/**
 * @brief		Helper function that executes eating philo routine.
 * 
 * @param philo	Philosopher that wants to eat.
 */
static void philo_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (philo->numb != data->nb_philo)
		pick_forks(data, philo->numb, philo->left_f, philo->right_f);
	else
		pick_forks(data, philo->numb, philo->right_f, philo->left_f);
	pthread_mutex_lock(&philo->e_mux);
	post(data, (philo->numb * 10 + EATING));
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->e_mux);
	ft_msleep(philo->to_eat, data);
	if (data->nb_2eat != -1)
	{
		pthread_mutex_lock(&philo->c_mux);
		philo->ate_c ++;
		pthread_mutex_unlock(&philo->c_mux);
	}
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
}

void	*philo(void *p)
{
	t_philo	*philo;

	((t_philo *)p)->last_meal = get_time();
	philo = (t_philo *)p;
	if (philo->numb % 2)
		usleep(1000);
	while (!is_ended(philo->data))
	{
		philo_eat(philo);
		ft_msleep(philo->to_eat, philo->data);
		post(philo->data, (philo->numb * 10 + SLEEPING));
		ft_msleep(philo->to_sleep, philo->data);
		post(philo->data, (philo->numb * 10 + THINKING));
	}
	return (NULL);
}
