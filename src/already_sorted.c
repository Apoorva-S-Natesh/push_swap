/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:01:50 by asomanah          #+#    #+#             */
/*   Updated: 2024/08/09 13:15:59 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
This function checks if the first n elements of a stack 
are in ascending order.*/

char	n_ascending(t_head *stack, size_t n)
{
	t_rlist	*current;

	if (!stack->list)
		return (0);
	current = stack->list;
	while (--n)
	{
		if (current->position > current->next->position)
			return (0);
		current = current->next;
	}
	return (1);
}
// This function checks if the first n elements of a stack are 
// in descending order.

char	n_descending(t_head *stack, size_t n)
{
	t_rlist	*current;

	if (!stack->list)
		return (0);
	current = stack->list;
	while (--n)
	{
		if (current->position < current->next->position)
			return (0);
		current = current->next;
	}
	return (1);
}

//This function finds the position of the largest element among the first n 
//elements in the stack.

size_t	biggest_ele(t_head *head, size_t n)
{
	size_t	current_pos;
	size_t	max_value;
	size_t	max_pos;
	t_rlist	*temp;

	if (!head->size)
		return (0);
	temp = head->list;
	max_pos = 1;
	max_value = temp->position;
	current_pos = 1;
	while (current_pos++ < n)
	{
		if (temp->next->position > max_value)
		{
			max_value = temp->next->position;
			max_pos = current_pos;
		}
		temp = temp->next;
	}
	return (max_pos);
}
