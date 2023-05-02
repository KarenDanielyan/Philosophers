/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:13:17 by kdaniely          #+#    #+#             */
/*   Updated: 2023/05/02 14:46:49 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief			Safely checks whether simulation is stopped.
 * 
 * @param	data	Data structure describing state of the simulation.
 * @return	int		0 - Not stopped, 1 - Stopped
 */
int	is_dead(t_data *data)
{
	int	rv;

	sem_wait(data->d_sem);
	rv = data->is_dead;
	sem_post(data->d_sem);
	return (rv);
}

static void	philo_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	sem_wait(data->forks);
	post(data, (philo->numb * 10 + PICKING));
	sem_wait(data->forks);
	post(data, (philo->numb * 10 + PICKING));
	sem_wait(data->t_sem);
	post(data, (philo->numb * 10 + EATING));
	philo->last_meal = get_time(0);
	sem_post(data->t_sem);
	ft_msleep(data->to_eat, data);
	sem_wait(data->c_sem);
	philo->ate_c ++;
	sem_post(data->c_sem);
	sem_post(data->forks);
	sem_post(data->forks);
}

void	*check_death(void *p)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)p;
	data = philo->data;
	while (1)
	{
		sem_wait(philo->data->t_sem);
		if ((get_time(0) - philo->last_meal) > data->to_die)
		{
			post(philo->data, (philo->numb * 10 + DEAD));
			sem_post(philo->data->t_sem);
			sem_wait(philo->data->p_sem);
			exit(EXIT_FAILURE);
		}
		sem_post(philo->data->t_sem);
		if (is_dead(data))
			break ;
		if (data->nb_2eat != -1 && philo->ate_c >= data->nb_2eat)
			break ;
	}
	return (NULL);
}

void	philo(void *p)
{
	t_philo	*philo;
	t_data	*data;

	get_time(42);
	philo = (t_philo *)p;
	data = philo->data;
	pthread_create(&(philo->death_check), NULL, &check_death, p);
	if (philo->numb % 2 == 0)
		usleep(1000);
	while (!is_dead(data))
	{
		philo_eat(philo);
		sem_wait(data->c_sem);
		if (data->nb_2eat != -1 && philo->ate_c >= data->nb_2eat)
		{
			sem_post(data->c_sem);
			break ;
		}
		sem_post(data->c_sem);
		post(data, (philo->numb * 10 + SLEEPING));
		ft_msleep(data->to_sleep, data);
		post(data, (philo->numb * 10 + THINKING));
	}
	pthread_join(philo->death_check, NULL);
	if (is_dead(data))
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
