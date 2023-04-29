/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:44:03 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/29 22:18:23 by kdaniely         ###   ########.fr       */
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
# define FORK_MSG "has taken a fork"

typedef struct timeval t_time;

typedef struct s_args
{
	int			philo_num;
	int			must_eat_count;
	long	time_to_die;
	long	time_to_sleep;
	long	time_to_eat;
}	t_args;

typedef enum e_state
{
	DEAD = 0,
	EATING = 1,
	PICKING = 2,
	SLEEPING = 3,
	THINKING = 4
}	t_state;

typedef struct s_philo
{
	int				numb;
	int				ate_c;
	long		to_sleep;
	long		to_die;
	long		to_eat;
	long		last_meal;
	pthread_mutex_t	e_mux;
	pthread_mutex_t	c_mux;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				is_ended;
	int				nb_philo;
	int				nb_2eat;
	pthread_mutex_t	p_mux;
	pthread_mutex_t	end_mux;
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	t_philo			*philos;
}	t_data;

#endif
