/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:45:41 by asomanah          #+#    #+#             */
/*   Updated: 2024/08/13 09:14:32 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

//Represents a node in a doubly linked list (which is circular or a "ring list")
typedef struct s_rlist
{
	int				data;
	struct s_rlist	*last;
	struct s_rlist	*next;
	size_t			position;
}	t_rlist;

//Represents the head (or metadata) of the stack (which is a doubly linked list)
typedef struct s_head
{
	size_t	size;
	t_rlist	*list;
}	t_head;

// Encapsulates both stack A and stack B.
typedef struct s_stacks
{
	size_t	total;
	t_head	*stk_a;
	t_head	*stk_b;
}	t_stacks;

// FILL AND INITIALIZE STACKS
char		stacks_init(t_stacks *stacks);
char		fill_stacks(t_stacks *stacks, int argc, char *argv[]);

// STACK UTILS
void		free_stacks(t_stacks *stacks);

// sorting in chunks - thirds
void		sort_from_left(t_stacks *stacks, size_t min_el, size_t max_el);
void		sort_from_right(t_stacks *stacks, size_t min_el, size_t max_el);

// Operations
void		swap(t_head *stack);
void		push(t_head *stack_one, t_head *stack_two);
void		rotate(t_head *stack);
void		reverse_rotate(t_head *stack);

// functions
t_stacks	*sa(t_stacks *stacks);
t_stacks	*sb(t_stacks *stacks);
t_stacks	*ss(t_stacks *stacks);
t_stacks	*ra(t_stacks *stacks);
t_stacks	*rb(t_stacks *stacks);
t_stacks	*rr(t_stacks *stacks);
t_stacks	*rra(t_stacks *stacks);
t_stacks	*rrb(t_stacks *stacks);
t_stacks	*rrr(t_stacks *stacks);
t_stacks	*pa(t_stacks *stacks);
t_stacks	*pb(t_stacks *stacks);
void		p_times(t_stacks *stacks, size_t n, char st_b);
t_stacks	*rr_times(t_stacks *stacks, size_t n, char st_b);

// Already sorted - Control
char		n_ascending(t_head *stack, size_t n);
char		n_descending(t_head *stack, size_t n);
size_t		biggest_ele(t_head *head, size_t n);

// small sorting - B
void		sort_two_b(t_stacks *st);
void		sort_three_b(t_stacks *st);
void		sort_four_b(t_stacks *st);
void		sort_five_b(t_stacks *st);

// small sorting - A
void		sort_two_a(t_stacks *st);
void		sort_three_a(t_stacks *st);
void		sort_four_a(t_stacks *st);
void		sort_five_a(t_stacks *st);

#endif