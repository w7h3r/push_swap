/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:34:54 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/25 07:36:19 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	push_to_stack(int *src, int *dst, int *src_size, int *dst_size)
{
	int		i;

	if (*src_size == 0)
		return ;
	i = *dst_size;
	while (i > 0)
	{
		dst[i] = dst[i - 1];
		i--;
	}
	dst[0] = src[0];
	i = 0;
	while (i < *src_size - 1)
	{
		src[i] = src[i + 1];
		i++;
	}
	(*src_size)--;
	(*dst_size)++;
}

void	pa(t_stacks *stack)
{
	if (stack->b_size == 0)
	{
		free_stacks(stack);
		exit (1);
	}
	push_to_stack(stack->b, stack->a, &stack->b_size, &stack->a_size);
	write(1, "pa\n", 3);
}

void	pb(t_stacks *stack)
{
	if (stack->a_size == 0)
	{
		free_stacks(stack);
		exit (1);
	}
	push_to_stack(stack->a, stack->b, &stack->a_size, &stack->b_size);
	write(1, "pb\n", 3);
}
