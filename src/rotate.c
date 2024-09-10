/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:23:10 by asomanah          #+#    #+#             */
/*   Updated: 2024/08/09 11:24:44 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stacks	*ra(t_stacks *stacks)
{
	rotate(stacks->stk_a);
	write(1, "ra\n", 3);
	return (stacks);
}

t_stacks	*rb(t_stacks *stacks)
{
	rotate(stacks->stk_b);
	write(1, "rb\n", 3);
	return (stacks);
}

t_stacks	*rr(t_stacks *stacks)
{
	rotate(stacks->stk_a);
	rotate(stacks->stk_b);
	write(1, "rr\n", 3);
	return (stacks);
}
