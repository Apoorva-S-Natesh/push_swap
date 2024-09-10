/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:04:34 by asomanah          #+#    #+#             */
/*   Updated: 2024/08/09 17:04:45 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stacks	*rra(t_stacks *stacks)
{
	reverse_rotate(stacks->stk_a);
	write(1, "rra\n", 4);
	return (stacks);
}

t_stacks	*rrb(t_stacks *stacks)
{
	reverse_rotate(stacks->stk_b);
	write(1, "rrb\n", 4);
	return (stacks);
}

t_stacks	*rrr(t_stacks *stacks)
{
	reverse_rotate(stacks->stk_a);
	reverse_rotate(stacks->stk_b);
	write(1, "rrr\n", 4);
	return (stacks);
}

t_stacks	*rr_times(t_stacks *stacks, size_t n, char st_b)
{
	if (st_b)
		while (n--)
			rrb(stacks);
	else
		while (n--)
			rra(stacks);
	return (stacks);
}
