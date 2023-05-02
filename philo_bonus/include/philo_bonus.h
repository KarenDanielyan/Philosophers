/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:05:42 by kdaniely          #+#    #+#             */
/*   Updated: 2023/05/02 15:05:17 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "defines_bonus.h"
# include <signal.h>
# include <stdint.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* Logic */
void		launch(t_data *data);
void		philo(void *p);

/* Initialization */
void		new_data(t_data *data, t_args args);

/* Input Parsing */
t_args		parse(int ac, char **av);
int			check_number(const char *s);

/* Event printing */
void		post(t_data *data, int code);

/* Utils*/
void		ft_msleep(long ms, t_data *data);
long		ft_atol(const char *str);
int			is_dead(t_data *data);
long long	get_time(t_data *data);

#endif
