/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:22:56 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/29 20:36:25 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

struct s_bundle
{
	t_args			args;
	pthread_mutex_t	*forks;
	t_data			*data;
};

static t_philo	*philo_init(t_data *data, t_args args)
{
	t_philo	*p;
	int		i;

	p = (t_philo *)malloc(args.philo_num
			* sizeof(t_philo));
	i = 0;
	while (i < data->nb_philo)
	{
		p[i].data = data;
		p[i].numb = i + 1;
		p[i].ate_c = 0;
		p[i].to_die = args.time_to_die;
		p[i].to_eat = args.time_to_eat;
		p[i].to_sleep = args.time_to_sleep;
		if (i == 0)
			p[i].right_f = &(data->forks[args.philo_num - 1]);
		else
			p[i].right_f = &(data->forks[i - 1]);
		p[i].left_f = &(data->forks[i]);
		pthread_mutex_init(&p[i].c_mux, NULL);
		pthread_mutex_init(&p[i].e_mux, NULL);
		i ++;
	}
	return (p);
}

void	new_data(t_data *data, t_args args)
{
	pthread_mutex_t	*m;

	data->is_ended = 0;
	data->nb_philo = args.philo_num;
	data->nb_2eat = args.must_eat_count;
	data->threads = (pthread_t *)malloc(args.philo_num
			* sizeof(pthread_t));
	data->forks = (pthread_mutex_t *)malloc(args.philo_num
			* sizeof(pthread_mutex_t));
	m = data->forks;
	while (m < (data->forks + args.philo_num))
		pthread_mutex_init(m++, NULL);
	pthread_mutex_init(&data->p_mux, NULL);
	pthread_mutex_init(&data->end_mux, NULL);
	data->philos = philo_init(data, args);
}
