/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:13:17 by kdaniely          #+#    #+#             */
/*   Updated: 2023/06/01 14:20:59 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	philo->last_meal = get_time(data);
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
	while (42)
	{
		sem_wait(data->t_sem);
		if ((get_time(data) - philo->last_meal) > data->to_die)
		{
			post(data, (philo->numb * 10 + DEAD));
			sem_post(data->t_sem);
			sem_wait(data->p_sem);
			exit(EXIT_FAILURE);
		}
		sem_post(data->t_sem);
		sem_wait(data->c_sem);
		if (data->nb_2eat != -1 && philo->ate_c >= data->nb_2eat)
		{
			sem_post(data->c_sem);
			break ;
		}
		sem_post(data->c_sem);
	}
	return (NULL);
}

void	philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	pthread_create(&(philo->death_check), NULL, &check_death, p);
	if (philo->numb % 2 == 0)
		usleep(1000);
	while (42)
	{
		philo_eat(philo);
		sem_wait(philo->data->c_sem);
		if (philo->data->nb_2eat != -1 && philo->ate_c >= philo->data->nb_2eat)
		{
			sem_post(philo->data->c_sem);
			break ;
		}
		sem_post(philo->data->c_sem);
		post(philo->data, (philo->numb * 10 + SLEEPING));
		ft_msleep(philo->data->to_sleep, philo->data);
		post(philo->data, (philo->numb * 10 + THINKING));
	}
	pthread_join(philo->death_check, NULL);
	exit(EXIT_SUCCESS);
}
