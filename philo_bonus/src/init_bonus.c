/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:22:56 by kdaniely          #+#    #+#             */
/*   Updated: 2023/05/01 22:26:24 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_philo	*philo_init(t_data *data, t_args args)
{
	t_philo	*p;
	int		i;

	p = (t_philo *)malloc(args.philo_num
			* sizeof(t_philo));
	if (p == NULL)
	{
		perror("malloc()");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		p->ate_c = 0;
		p->numb = i + 1;
		p->last_meal = 0;
		p->nb_2eat = args.must_eat_count;
		p->to_die = args.time_to_die;
		p->to_eat = args.time_to_eat;
		p->to_sleep = args.time_to_sleep;
		p->data = data;
	}
	return (p);
}

void	new_data(t_data *data, t_args args)
{
	data->nb_philo = args.philo_num;
	data->pid_s = (int *)malloc(args.philo_num * sizeof(int));
	if (data->pid_s == NULL)
	{
		perror("malloc()");
		exit(EXIT_FAILURE);
	}
	sem_unlink(FORK_SEM_NAME);
	sem_unlink(MEAL_SEM_NAME);
	sem_unlink(PRINT_SEM_NAME);
	sem_unlink(MCOUNT_SEM_NAME);	
	data->forks = sem_open(FORK_SEM_NAME, O_CREAT, S_IRWXU, data->nb_philo);
	data->p_sem = sem_open(PRINT_SEM_NAME, O_CREAT, S_IRWXU, 1);
	data->c_sem = sem_open(MEAL_SEM_NAME, O_CREAT, S_IRWXU, 1);
	data->m_sem = sem_open(MCOUNT_SEM_NAME, O_CREAT, S_IRWXU, 1);
	if (data->p_sem == SEM_FAILED || data->c_sem == SEM_FAILED
		|| data->forks == SEM_FAILED)
	{
		perror("sem_open()");
		exit(EXIT_FAILURE);
	}
	data->philos = philo_init(data, args);
}
