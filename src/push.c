/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:40:11 by asomanah          #+#    #+#             */
/*   Updated: 2024/08/09 17:05:04 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stacks	*pa(t_stacks *stacks)
{
	push(stacks->stk_b, stacks->stk_a);
	write(1, "pa\n", 3);
	return (stacks);
}

t_stacks	*pb(t_stacks *stacks)
{
	push(stacks->stk_a, stacks->stk_b);
	write(1, "pb\n", 3);
	return (stacks);
}

void	p_times(t_stacks *stacks, size_t n, char st_b)
{
	if (st_b)
		while (n--)
			pb(stacks);
	else
		while (n--)
			pa(stacks);
}
