/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:08:02 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/25 07:37:34 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <unistd.h>

void	rotate_stack(int *stack, int *size)
{
	int	i;
	int	temp;

	if (*size < 2)
		return ;
	temp = stack[0];
	i = 0;
	while (i < *size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[*size - 1] = temp;
}

void	ra(t_stacks *stack)
{
	if (stack->a[0])
		rotate_stack(stack->a, &stack->a_size);
	write(1, "ra\n", 3);
}

void	rb(t_stacks *stack)
{
	if (stack->b[0])
		rotate_stack(stack->b, &stack->b_size);
	write(1, "rb\n", 3);
}

void	rr(t_stacks *stack)
{
	if (stack->a[0] && stack->b[0])
	{
		rotate_stack(stack->a, &stack->a_size);
		rotate_stack(stack->b, &stack->b_size);
	}
	write(1, "rr\n", 3);
}
