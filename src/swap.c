/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:13:34 by asomanah          #+#    #+#             */
/*   Updated: 2024/08/09 11:18:49 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stacks	*sa(t_stacks *stacks)
{
	swap(stacks->stk_a);
	write(1, "sa\n", 3);
	return (stacks);
}

t_stacks	*sb(t_stacks *stacks)
{
	swap(stacks->stk_b);
	write(1, "sb\n", 3);
	return (stacks);
}

t_stacks	*ss(t_stacks *stacks)
{
	swap(stacks->stk_a);
	swap(stacks->stk_b);
	write(1, "ss\n", 3);
	return (stacks);
}
