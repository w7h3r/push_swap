/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 07:23:58 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/25 07:30:12 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <unistd.h>

void	rev_rotate_stack(int *stack, int *size)
{
	int	i;
	int	temp;

	if (*size < 2)
		return ;
	temp = stack[*size - 1];
	i = *size;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
}

void	rra(t_stacks *stack)
{
	if (stack->a[0])
		rotate_stack(stack->a, &stack->a_size);
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *stack)
{
	if (stack->b[0])
		rotate_stack(stack->b, &stack->b_size);
	write(1, "rrb\n", 4);
}

void	rrr(t_stacks *stack)
{
	if (stack->a[0] && stack->b[0])
	{
		rotate_stack(stack->a, &stack->a_size);
		rotate_stack(stack->b, &stack->b_size);
	}
	write(1, "rrr\n", 4);
}

