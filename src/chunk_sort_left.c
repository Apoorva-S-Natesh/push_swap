/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:34:54 by asomanah          #+#    #+#             */
/*   Updated: 2024/08/13 12:31:18 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	thirds_right(t_stacks *st, size_t min, size_t max, size_t size);
static void	sort_back_left(t_stacks *st, size_t min, size_t max, size_t trd);

void	sort_from_left(t_stacks *stacks, size_t min_el, size_t max_el)
{
	size_t	size;

	size = max_el - min_el + 1;
	if (n_ascending(stacks->stk_a, size))
		return ;
	if (size > 5)
		thirds_right(stacks, min_el, max_el, size);
	else if (size == 5)
		sort_five_a(stacks);
	else if (size == 4)
		sort_four_a(stacks);
	else if (size == 3)
		sort_three_a(stacks);
	else if (size == 2)
		sort_two_a(stacks);
}

// sorts from left two thirds to right up/bottom

static void	thirds_right(t_stacks *st, size_t min, size_t max, size_t size)
{
	size_t	trd;
	size_t	i;

	trd = size / 3;
	if (size % 3 == 2)
		trd++;
	i = 0;
	while (i++ < size)
	{
		if (st->stk_a->list->position < min + trd)
		{
			if (st->stk_a->list->next->position >= min + 2 * trd && i < size)
			{
				rr(pb(st));
				i++;
			}
			else
				rb(pb(st));
		}
		else if (st->stk_a->list->position < min + 2 * trd)
			pb(st);
		else
			ra(st);
	}
	sort_back_left(st, min, max, trd);
}

static void	sort_back_left(t_stacks *st, size_t min, size_t max, size_t trd)
{
	if (st->stk_a->size > max - min + 1 - 2 * trd)
		rr_times(st, max - min + 1 - 2 * trd, 0);
	sort_from_left(st, min + 2 * trd, max);
	sort_from_right(st, min + trd, min + 2 * trd - 1);
	if (st->stk_b->size > trd)
		rr_times(st, trd, 1);
	sort_from_right(st, min, min + trd - 1);
}
