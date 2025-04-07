/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:03:15 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/22 01:08:11 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdlib.h>

void	free_stacks(t_stacks *stack, int con)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack->idx_a)
		free(stack->idx_a);
	exit(con);
}

_Bool	stack_repeat(t_stacks *stack)
{
	int		i;
	int		j;

	i = 0;
	while (i < stack->a_size)
	{
		j = i + 1;
		while (j < stack->a_size)
		{
			if (stack->a[j] == stack->a[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	stack_sorted(t_stacks *stack)
{
	int	i;

	i = 0;
	while (i < stack->a_size - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	is_valid_stack(t_stacks *stack)
{
	if (stack_repeat(stack))
		err_exit(stack);
	if (stack_sorted(stack))
		free_stacks(stack, 0);
}

void	copy_stacks(int *src, int *dst, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}
