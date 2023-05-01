/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:44:03 by kdaniely          #+#    #+#             */
/*   Updated: 2023/05/01 22:19:35 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_BONUS_H
# define DEFINES_BONUS_H

# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>

# define DEAD_MSG		"died"
# define EATING_MSG		"is eating"
# define SLEEPING_MSG	"is sleeping"
# define THINKING_MSG	"is thinking"
# define FORK_MSG		"has taken a fork"

# define FORK_SEM_NAME	"/philo_forks"
# define PRINT_SEM_NAME	"/philo_print"
# define MEAL_SEM_NAME	"/philo_meal"
# define DEAD_SEM_NAME	"/philo_dead"
# define MCOUNT_SEM_NAME "/philo_mcount"

typedef struct timeval	t_time;

typedef struct s_args
{
	int			philo_num;
	int			must_eat_count;
	long		time_to_die;
	long		time_to_sleep;
	long		time_to_eat;
}	t_args;

typedef enum e_state
{
	DEAD = 0,
	EATING = 1,
	PICKING = 2,
	SLEEPING = 3,
	THINKING = 4
}	t_state;

/**
 * @brief Structure describing my philosophers
 * 
 * @param numb			Philosophers index,
 * @param nb_2eat		Number of time philo must eat to finish simulation,
 * @param ate_c			Number of times philo ate,
 * @param to_sleep		Time it takes for philo to sleep,
 * @param to_die		Amount of time philo can starve, if he does not it during
 * @param to_eat		Time it takes for philo to eat,
 * @param last_meal		Timestamp of last time philo ate,
 * @param data			Pointer to the structure that contains names semaphore,
 * @param end_check		Dedicated thread to check whether philo died or not.
 */
typedef struct s_philo
{
	int				numb;
	int				nb_2eat;
	int				ate_c;
	long			to_sleep;
	long			to_die;
	long			to_eat;
	long			last_meal;
	struct s_data	*data;
	pthread_t		end_check;
}	t_philo;

/**
 * @brief	Structure describing the state of my simulation.
 * 
 * @param	is_ended	Shows whether simulation ended for given philo or not,
 * @param	nb_phil		Number of philosophers participating in simulation,
 * @param	pid_s		Array conteining process id's of philos,
 * @param	p_sem		Binary semaphore protecting against scrambled view,
 * @param	c_sem		Binary semaphore protecting ate_c state,
 * @param	m_sem		Binary semaphore protecting last_meal time,
 * @param	forks		Counting semaphore representing available forks,
 * @param	philos		Array of philosophers.
 */
typedef struct s_data
{
	int			is_ended;
	int			nb_philo;
	int			*pid_s;
	sem_t		*m_sem;
	sem_t		*c_sem;
	sem_t		*p_sem;
	sem_t		*forks;
	t_philo		*philos;
}	t_data;

#endif
