/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 23:09:53 by asomanah          #+#    #+#             */
/*   Updated: 2024/08/12 20:38:54 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_back_right(t_stacks *st, size_t min, size_t max, size_t trd);
static void	thirds_left(t_stacks *st, size_t min, size_t max, size_t size);

void	sort_from_right(t_stacks *stacks, size_t min_el, size_t max_el)
{
	size_t	size;

	size = max_el - min_el + 1;
	if (n_descending(stacks->stk_b, size))
		return (p_times(stacks, size, 0));
	if (size > 5)
		thirds_left(stacks, min_el, max_el, size);
	else if (size == 5)
		sort_five_b(stacks);
	else if (size == 4)
		sort_four_b(stacks);
	else if (size == 3)
		sort_three_b(stacks);
	else if (size == 2)
		sort_two_b(stacks);
	else if (size == 1)
		pa(stacks);
}

static void	thirds_left(t_stacks *st, size_t min, size_t max, size_t size)
{
	size_t	trd;
	size_t	i;

	trd = size / 3;
	if (size % 3 == 2)
		trd++;
	i = 0;
	while (i++ < size)
	{
		if (st->stk_b->list->position < min + trd)
			rb(st);
		else if (st->stk_b->list->position < min + 2 * trd)
		{
			if (st->stk_b->list->next->position < min + trd && i < size)
			{
				rr(pa(st));
				i++;
			}
			else
				ra(pa(st));
		}
		else
			pa(st);
	}
	sort_back_right(st, min, max, trd);
}

static void	sort_back_right(t_stacks *st, size_t min, size_t max, size_t trd)
{
	sort_from_left(st, min + 2 * trd, max);
	if (st->stk_a->size > trd)
		rr_times(st, trd, 0);
	sort_from_left(st, min + trd, min + 2 * trd - 1);
	if (st->stk_b->size > trd)
		rr_times(st, trd, 1);
	sort_from_right(st, min, min + trd - 1);
}
