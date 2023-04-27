/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:44:03 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/27 16:05:56 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <pthread.h>
# include <sys/time.h>

# define DEAD_MSG "died"
# define EATING_MSG "is eating"
# define SLEEPING_MSG "is sleeping"
# define THINKING_MSG "is thinking"

typedef struct timeval t_time;

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
	long			ms;
	int				msg_code;
	struct s_queue	*next;
}	t_queue;

typedef struct s_philo
{
	int				numb;
	int				to_sleep;
	int				to_die;
	int				to_eat;
	int				ate_c;
	t_state			stat;
	pthread_mutex_t	*q_mux;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	t_queue			**msg_q;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	q_mux;
	pthread_t		*threads;
	t_philo			*philos;
	t_queue			*msg_q;
}	t_data;

#endif
