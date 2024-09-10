/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:55:11 by asomanah          #+#    #+#             */
/*   Updated: 2024/08/12 15:26:02 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc == 1)
		return (1);
	if (!stacks_init(&stacks))
		return (ft_putstr_fd("Error\n", 2), 1);
	if (!fill_stacks(&stacks, argc, argv))
	{
		free_stacks(&stacks);
		return (ft_putstr_fd("Error\n", 2), 1);
	}
	if (stacks.total)
		sort_from_left(&stacks, 1, stacks.total);
	free_stacks(&stacks);
	return (0);
}
