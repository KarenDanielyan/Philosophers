/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:32:13 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/29 22:37:20 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	death_check(t_data *data)
{
	t_philo	*p;
	int		i;

	p = data->philos;
	i = 0;
	while (i < data->nb_philo && !is_ended(data))
	{
		pthread_mutex_lock(&((p + i)->e_mux));
		if ((get_time(0) - (p + i)->last_meal) > (p + i)->to_die)
		{
			post(data, ((p + i)->numb * 10 + DEAD));
			pthread_mutex_lock(&(data->end_mux));
			data->is_ended = 1;
			pthread_mutex_unlock(&(data->end_mux));
		}
		pthread_mutex_unlock(&((p + i)->e_mux));
		i ++;
	}
}

static void	eat_check(t_data *data)
{
	int		i;
	t_philo	*p;

	i = 0;
	p = data->philos;
	while (data->nb_2eat != -1 && i < data->nb_philo)
	{
		pthread_mutex_lock(&p[i].c_mux);
		if (p[i].ate_c >= data->nb_2eat)
			i ++;
		else
			break;
		pthread_mutex_unlock(&p[i].c_mux);
	}
	if (i != data->nb_philo)
		pthread_mutex_unlock(&p[i].c_mux);
	if (i == data->nb_philo)
	{
		pthread_mutex_lock(&(data->end_mux));
		data->is_ended = 1;
		pthread_mutex_unlock(&(data->end_mux));
	}
}

static void	check_end(t_data *data)
{
	while (!is_ended(data))
	{
		death_check(data);
		if (data->is_ended)
			break ;
		eat_check(data);
	}
}

static void	terminate(t_data *data)
{
	int	i;

	i = -1;
	if (data->nb_philo != 1)
	{
		while (++i < data->nb_philo)
			pthread_join(data->threads[i], NULL);
	}
	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->philos->c_mux));
	pthread_mutex_destroy(&(data->philos->e_mux));
	pthread_mutex_destroy(&(data->end_mux));
	pthread_mutex_destroy(&data->p_mux);
}

void	launch(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->threads[i], NULL, &philo, (void *)(&data->philos[i])))
		{
			perror("thread_create");
			exit(EXIT_FAILURE);
		}
		i ++;
	}
	check_end(data);
	terminate(data);
}
