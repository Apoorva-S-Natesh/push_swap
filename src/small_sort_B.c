/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_B.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:37:18 by asomanah          #+#    #+#             */
/*   Updated: 2024/08/12 16:47:57 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two_b(t_stacks *st)
{
	if (st->stk_b->list->position < st->stk_b->list->next->position)
		pa(sb(st));
	else
		pa(st);
	pa(st);
}

void	sort_three_b(t_stacks *st)
{
	size_t	biggest;

	biggest = biggest_ele(st->stk_b, 3);
	if (biggest == 1)
		sort_two_b(pa(st));
	else if (biggest == 2)
		sort_two_b(pa(sb(st)));
	else
	{
		if (st->stk_b->size == 3)
			sort_two_b(pa(rrb(st)));
		else
			sort_two_b(rrb(pa(sb(rb(st)))));
	}
}

void	sort_four_b(t_stacks *st)
{
	size_t	biggest;

	biggest = biggest_ele(st->stk_b, 4);
	if (biggest == 1)
		sort_three_b(pa(st));
	else if (biggest == 2)
		sort_three_b(pa(sb(st)));
	else if (st->stk_b->size == 4)
	{
		if (biggest == 3)
			sort_three_b(pa(sb(rb(st))));
		else
			sort_three_b(pa(rrb(st)));
	}
	else if (biggest == 3)
		sort_three_b(rrb(pa(sb(rb(st)))));
	else
		sort_three_b(rrb(rrb(pa(sb(rb(rb(st)))))));
}

void	sort_five_b(t_stacks *st)
{
	size_t	biggest;

	biggest = biggest_ele(st->stk_b, 5);
	if (biggest == 1)
		sort_four_b(pa(st));
	else if (biggest == 2)
		sort_four_b(pa(sb(st)));
	else if (st->stk_b->size == 5)
	{
		if (biggest == 3)
			sort_four_b(pa(rb(rb(st))));
		else if (biggest == 4)
			sort_four_b(pa(rrb(rrb(st))));
		else
			sort_four_b(pa(rrb(st)));
	}
	else if (biggest == 3)
		sort_four_b(rrb(pa(sb(rb(st)))));
	else if (biggest == 4)
		sort_four_b(rrb(rrb(pa(sb(rb(rb(st)))))));
	else
		sort_four_b(rrb(rrb(rrb(pa(sb(rb(rb(rb(st)))))))));
}
