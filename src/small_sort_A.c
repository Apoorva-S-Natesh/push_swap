/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_A.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:37:29 by asomanah          #+#    #+#             */
/*   Updated: 2024/08/12 20:38:48 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two_a(t_stacks *st)
{
	if (st->stk_a->list->position > st->stk_a->list->next->position)
		sa(st);
}

void	sort_three_a(t_stacks *st)
{
	size_t	biggest;

	biggest = biggest_ele(st->stk_a, 3);
	if (st->stk_a->size == 3 && biggest == 1)
		sort_two_a(ra(st));
	else if (biggest == 1)
		sort_two_a(rra(sa(ra(sa(st)))));
	else if (st->stk_a->size == 3 && biggest == 2)
		sort_two_a(rra(st));
	else if (biggest == 2)
		sort_two_a(rra(sa(ra(st))));
	else
		sort_two_a(st);
}

void	sort_four_a(t_stacks *st)
{
	size_t	biggest;

	biggest = biggest_ele(st->stk_a, 4);
	if (biggest == 4)
		sort_three_a(st);
	else if (st->stk_a->size == 4)
	{
		if (biggest == 1)
			sort_three_a(ra(st));
		else if (biggest == 2)
			sort_three_a(ra(ra(st)));
		else if (biggest == 3)
			sort_three_a(rra(st));
	}
	else if (biggest == 3)
		sort_three_b(pb(sa(pb(pb(st)))));
	else if (biggest == 2)
		sort_three_b(pb(sa(pb(sa(pb(st))))));
	else
		sort_three_b(rra(pb(pb(pb(ra(st))))));
}

void	sort_five_a(t_stacks *st)
{
	size_t	biggest;

	biggest = biggest_ele(st->stk_a, 5);
	if (biggest == 5)
		sort_four_a(st);
	else if (st->stk_a->size == 5)
	{
		if (biggest == 4)
			sort_four_a(rra(st));
		else if (biggest == 3) 
			sort_four_a(rra(rra(st)));
		else if (biggest == 2)
			sort_four_a(ra(ra(st)));
		else
			sort_four_a(ra(st));
	}
	else if (biggest == 4)
		sort_four_b(pb(sa(pb(pb(pb(st))))));
	else if (biggest == 3)
		sort_four_b(pb(sa(pb(sa(pb(pb(st)))))));
	else if (biggest == 2)
		sort_four_b(rra(pb(pb(pb(ra(pb(st)))))));
	else
		sort_four_b(rra(pb(pb(pb(pb(ra(st)))))));
}
