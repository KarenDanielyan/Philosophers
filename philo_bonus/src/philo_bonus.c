/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:13:17 by kdaniely          #+#    #+#             */
/*   Updated: 2023/05/01 21:57:32 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	philo_eat(t_philo *philo)
{
	sem_wait(philo->data->forks);
	post(philo->data, (philo->numb * 10 + PICKING));
	sem_wait(philo->data->forks);
	post(philo->data, (philo->numb * 10 + PICKING));
	post(philo->data, (philo->numb * 10 + EATING));
	sem_wait(philo->data->m_sem);
	philo->last_meal = get_time(0);
	sem_post(philo->data->m_sem);
	ft_msleep(philo->to_eat);
	sem_wait(philo->data->c_sem);
	philo->ate_c ++;
	sem_post(philo->data->c_sem);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	*check_end(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1)
	{
		sem_wait(philo->data->m_sem);
		if ((get_time(0) - philo->last_meal) > philo->to_die)
		{
			post(philo->data, (philo->numb * 10 + DEAD));
			sem_post(philo->data->m_sem);
			sem_wait(philo->data->p_sem);
			exit(EXIT_FAILURE);
		}
		sem_post(philo->data->m_sem);
		if (philo->nb_2eat != -1 && philo->ate_c >= philo->nb_2eat)
			break ;
	}
	return (NULL);
}

void	philo(void *p)
{
	t_philo	*philo;

	get_time(42);
	philo = (t_philo *)p;
	pthread_create(&philo->end_check, NULL, p, &check_end);
	if (philo->numb % 2 == 0)
		usleep(1000);
	while (42)
	{
		philo_eat(philo);
		sem_wait(philo->data->c_sem);
		if (philo->nb_2eat != -1 && philo->ate_c >= philo->nb_2eat)
			break ;
		post(philo->data, (philo->numb * 10 + SLEEPING));
		ft_msleep(philo->to_sleep);
		post(philo->data, (philo->numb * 10 + THINKING));
	}
	pthread_join(philo->end_check, NULL);
	exit(EXIT_SUCCESS);
}
