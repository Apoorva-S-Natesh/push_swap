/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:03:45 by asomanah          #+#    #+#             */
/*   Updated: 2024/08/12 12:39:20 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stacks(t_stacks *stacks)
{
	t_rlist	*tmp;

	if (stacks->stk_a)
	{
		while (stacks->stk_a->size--)
		{
			tmp = stacks->stk_a->list->next;
			free(stacks->stk_a->list);
			stacks->stk_a->list = tmp;
		}
		free(stacks->stk_a);
	}
	if (stacks->stk_b)
	{
		while (stacks->stk_b->size--)
		{
			tmp = stacks->stk_b->list->next;
			free(stacks->stk_b->list);
			stacks->stk_b->list = tmp;
		}
		free(stacks->stk_b);
	}
}
