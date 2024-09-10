/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:21:58 by asomanah          #+#    #+#             */
/*   Updated: 2024/08/09 17:05:18 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	add_ele_on_stack(t_rlist *element, t_head *stack);

void	swap(t_head *stack)
{
	t_rlist	*first;
	t_rlist	*second;

	if (stack->size < 2)
		return ;
	else if (stack->size == 2)
		return (rotate(stack));
	first = stack->list;
	second = stack->list->next;
	first->last->next = second;
	second->next->last = first;
	first->next = second->next;
	second->last = first->last;
	first->last = second;
	second->next = first;
	stack->list = second;
}

void	push(t_head *stack_one, t_head *stack_two)
{
	t_rlist	*temp;

	if (!stack_one->list)
		return ;
	temp = stack_one->list;
	stack_one->size--;
	if (!stack_one->size)
		stack_one->list = NULL;
	else
	{
		stack_one->list = stack_one->list->next;
		stack_one->list->last = temp->last;
		temp->last->next = stack_one->list;
	}
	add_ele_on_stack(temp, stack_two);
}

static void	add_ele_on_stack(t_rlist *element, t_head *stack)
{
	if (!stack->list)
	{
		stack->list = element;
		element->next = element;
		element->last = element;
	}
	else
	{
		element->next = stack->list;
		element->last = stack->list->last;
		stack->list->last->next = element;
		stack->list->last = element;
		stack->list = element;
	}
	stack->size++;
}

void	rotate(t_head *stack)
{
	if (stack->list)
		stack->list = stack->list->next;
}

void	reverse_rotate(t_head *stack)
{
	if (stack->list)
		stack->list = stack->list->last;
}
