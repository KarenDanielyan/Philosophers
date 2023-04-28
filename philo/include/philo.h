/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:05:42 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/28 22:25:19 by kdaniely         ###   ########.fr       */
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

/* Initialization */
void	new_data(t_data *data, t_args args);

/* Input Parsing */
t_args	parse(int ac, char **av);
int		check_number(const char *s);

/* Messaging queue */
void	post(t_queue **head, t_time t, int code);
void	fire(t_queue **head);

/* Utils*/
long	ft_atol(const char *str);
int		is_ended(t_data *data);
void	get_time(t_time *t);

#endif
