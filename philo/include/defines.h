/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:44:03 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/22 19:15:37 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <pthread.h>

# define DEAD_MSG "died"
# define EATING_MSG "is eating"
# define SLEEPING_MSG "is sleeping"
# define THINKING_MSG "is thinking"

typedef struct s_args
{
	int	philo_num;
	int	time_to_die;
	int	time_to_sleep;
	int	time_to_eat;
	int	must_eat_count;
}	t_args;

typedef enum e_state
{
	DEAD,
	EATING,
	SLEEPING,
	THINKING
}	t_state;

typedef struct s_queue
{
	int				msg_code;
	struct s_queue	*next;
}	t_queue;

typedef struct s_philo
{
	int				numb;
	int				ate_c;
	int				to_eat;
	int				to_die;
	int				to_sleep;
	t_state			stat;
	pthread_mutex_t	**forks;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	t_philo			*philos;
	t_queue			*msg_q;
}	t_data;

#endif
