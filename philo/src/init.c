/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:22:56 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/29 16:21:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	new_philo(t_philo *p, int num, pthread_mutex_t *forks, t_args args)
{
	p->numb = num;
	p->ate_c = 0;
	p->to_die = args.time_to_die;
	p->to_eat = args.time_to_eat;
	p->to_sleep = args.time_to_sleep;
	if (num == 0)
		p->right_f = &forks[args.philo_num - 1];
	else
		p->right_f = &forks[num - 1];
	p->left_f = &forks[num];
}

void	new_data(t_data *data, t_args args)
{
	pthread_mutex_t	*m;
	t_philo			*p;

	data->is_ended = 0;
	data->nb_philo = args.philo_num;
	data->nb_2eat = args.must_eat_count;
	data->threads = (pthread_t *)malloc(args.philo_num
			* sizeof(pthread_t));
	data->forks = (pthread_mutex_t *)malloc(args.philo_num
			* sizeof(pthread_mutex_t));
	data->philos = (t_philo *)malloc(args.philo_num
			* sizeof(t_philo));
	m = data->forks;
	while (m < (data->forks + args.philo_num))
		pthread_mutex_init(m++, NULL);
	pthread_mutex_init(&data->p_mux, NULL);
	pthread_mutex_init(&data->end_mux, NULL);
	p = data->philos;
	while (p < data->philos + args.philo_num)
	{
		new_philo(p, (p - (data->philos)) / sizeof(t_philo),
			data->forks, args);
		p ++;
	}
}
