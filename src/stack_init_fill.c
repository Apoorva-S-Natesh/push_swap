/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:02:25 by asomanah          #+#    #+#             */
/*   Updated: 2024/08/13 12:21:30 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char			add_elements(t_head *stack, char *argv[], int i);
static t_rlist		*create_ring_el(t_head *stack, char *str);
static size_t		check_position(t_rlist *tmp, int value);

// static function creates a new element (node) for the ring list (stack).

static t_rlist	*create_ring_el(t_head *stack, char *str)
{
	t_rlist	*new;
	int		value;
	size_t	position;

	if (*str == '\0' || !ft_isai(str))
		return (0);
	value = ft_atoi(str);
	if (*str == '-' && !value)
		return (NULL);
	if (*str != '-' && value == -1)
		return (NULL);
	position = check_position(stack->list, value);
	if (!position)
		return (NULL);
	new = (t_rlist *)malloc(sizeof(t_rlist));
	if (!new)
		return (NULL);
	new->data = value;
	new->next = NULL;
	new->last = NULL;
	new->position = position;
	return (new); 
}

// static function adds elements to the stack from the command-line arguments.
static char	add_elements(t_head *stack, char *argv[], int i)
{
	t_rlist	**endpointer_to_next;
	t_rlist	*new_el;
	t_rlist	*old_el;

	endpointer_to_next = &(stack->list);
	old_el = stack->list;
	while (argv[++i])
	{
		new_el = create_ring_el(stack, argv[i]);
		if (!new_el)
			return (0);
		new_el->last = old_el;
		*endpointer_to_next = new_el;
		endpointer_to_next = &(new_el->next);
		old_el = new_el;
		stack->size++;
	}
	*endpointer_to_next = stack->list;
	if (stack->list)
		stack->list->last = old_el;
	return (1);
}
// static function checks if a value is already in the stack and calculates the 
//correct position for the new value in a sorted order.

static size_t	check_position(t_rlist *tmp, int value)
{
	size_t	position;

	position = 1;
	while (tmp)
	{
		if (tmp->data == value)
			return (0);
		else if (tmp->data < value)
			position++;
		else
			tmp->position++;
		tmp = tmp->next;
	}
	return (position);
}

/* The program initializes the stacks, ensuring that memory allocation is 
successful and that both stacks are ready to hold elements.*/

char	stacks_init(t_stacks *stacks)
{
	stacks->stk_b = NULL;
	stacks->stk_a = (t_head *)malloc(sizeof(t_head));
	if (!stacks->stk_a)
		return (0);
	stacks->stk_b = (t_head *)malloc(sizeof(t_head));
	if (!stacks->stk_b)
	{
		free(stacks->stk_a);
		return (0);
	}
	stacks->stk_a->size = 0;
	stacks->stk_a->list = NULL;
	stacks->stk_b->size = 0;
	stacks->stk_b->list = NULL;
	return (1);
}

// fills stack A with the given elements from the command-line arguments.

char	fill_stacks(t_stacks *stacks, int argc, char *argv[])
{
	int		i;
	char	out;

	if (argc == 2)
	{
		if (!*argv[1] || *argv[1] == ' ')
			return (0);
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (0);
		argc = 0;
		i = -1;
	}
	else
		i = 0;
	out = add_elements(stacks->stk_a, argv, i);
	if (!argc)
		ft_split_free(argv);
	stacks->total = stacks->stk_a->size;
	return (out);
}
