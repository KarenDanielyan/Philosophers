/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:32:13 by kdaniely          #+#    #+#             */
/*   Updated: 2023/05/01 21:40:21 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	close_sems(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->c_sem);
	sem_close(data->p_sem);
	sem_close(data->m_sem);
	sem_unlink(FORK_SEM_NAME);
	sem_unlink(MEAL_SEM_NAME);
	sem_unlink(PRINT_SEM_NAME);
	sem_unlink(MCOUNT_SEM_NAME);	
}

void	terminate(t_data *data)
{
	int	i;
	int	rv;

	i = 0;
	while (i < data->nb_philo)
	{
		waitpid(-1, &rv, 0);
		if (WEXITSTATUS(rv) > 0)
		{
			i = -1;
			while (++i < data->nb_philo)
				kill(data->pid_s[i], SIGKILL);
			break ;
		}
		i ++;
	}
	close_sems(data);
}

void	launch(t_data *data)
{
	int		i;
	t_philo	*p;

	i = -1;
	p = data->philos;
	while (++i < data->nb_philo)
	{
		data->pid_s[i] = fork();
		if (data->pid_s[i] == -1)
		{
			perror("fork()");
			exit(EXIT_FAILURE);
		}
		if (data->pid_s[i] == 0)
			philo((void *)(data->philos + i));
	}
	terminate(data);
}
