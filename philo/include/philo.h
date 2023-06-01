/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:05:42 by kdaniely          #+#    #+#             */
/*   Updated: 2023/06/01 15:01:58 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "defines.h"
# include <sys/time.h>
# include <stdint.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* Logic */
int		launch(t_data *data);
void	*philo(void *p);

/* Initialization */
void	new_data(t_data *data, t_args args);

/* Input Parsing */
t_args	parse(int ac, char **av);
int		check_number(const char *s);

/* Event printing */
void	post(t_data *data, int code);

/* Utils*/
void	ft_msleep(long us, t_data *data);
long	ft_atol(const char *str);
int		is_ended(t_data *data);
long	get_time(int c);

#endif
