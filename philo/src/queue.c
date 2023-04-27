/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:21:01 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/27 16:13:16 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static t_queue	*queue_last(t_queue *head)
{
	if (head)
	{
		while (head->next)
			head = head->next;
	}
	return (head);
}

/*
*	Description: Return node before last, or NULL;
*	NOTE: If queue size is 1, blast == last
*/
static t_queue	*queue_before_last(t_queue *head)
{
	t_queue	*last;

	last = queue_last(head);
	if (head)
	{
		while (head->next != last)
			head = head->next;
	}
	return (head);
}

static int		queue_size(t_queue *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i ++;
	}
	return (i);
}

void	post(t_queue **head, t_time t, int code)
{
	t_queue	*msg;

	msg = (t_queue *)malloc(sizeof(t_queue));
	msg->msg_code = code;
	msg->ms = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	msg->next = *head;
	*head = msg;
}

void	fire(t_queue **head)
{
	t_queue	*last;
	t_queue	*before_last;

	if (head)
	{
		last = queue_last(*head);
		if (queue_size(*head) > 1)
		{
			before_last = queue_before_last(*head);
			before_last->next = NULL;
		}
		else
			*head = NULL;
		printf("%ld %d %s\n", last->ms, (last->msg_code % 10), EATING_MSG);
		free(last);
	}
}
