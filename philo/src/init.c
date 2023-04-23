/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:22:56 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/24 01:16:15 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	new_philo(t_philo *p, int num, pthread_mutex_t *forks, t_args args)
{
	p->numb = num;
	p->stat = THINKING;
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

	data->threads = (pthread_t *)malloc(args.philo_num
			* sizeof(pthread_t));
	data->forks = (pthread_mutex_t *)malloc(args.philo_num
			* sizeof(pthread_mutex_t));
	data->philos = (t_philo *)malloc(args.philo_num
			* sizeof(t_philo));
	FOREACH(m, data->forks, args.philo_num)
		pthread_mutex_init(m, NULL);
	FOREACH(p, data->philos,args.philo_num)
	{
		new_philo(p, (p - (data->philos)) / sizeof(t_philo),
			data->forks, args);
	}
	data->msg_q = NULL;
}
