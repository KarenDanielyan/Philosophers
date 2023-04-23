/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:05:42 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/23 20:25:13 by kdaniely         ###   ########.fr       */
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
long	ft_atol(const char *str);
int		check_number(const char *s);

#endif
