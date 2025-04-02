/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:28:31 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/27 02:13:58 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../inc/push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

void	bubble_sort_stack(t_stacks *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->a_size)
	{
		stack->idx_a[i] = stack->a[i];
		i++;
	}
	i = 0;
	while (i < stack->a_size - 1)
	{
		j = 0;
		while (j < stack->a_size - i - 1)
		{
			if (stack->idx_a[j] > stack->idx_a[j + 1])
				swap(&stack->idx_a[j], &stack->idx_a[j + 1]);
			j++;
		}
		i++;
	}
}

void	index_stack(t_stacks *stack)
{
	int	i;

	i = 0;
	while (i < stack->a_size)
	{
		stack->idx_a[i] = i;
		i++;
	}
}

void	radix_sort(t_stacks *stack)
{
	bubble_sort_stack(stack);
	index_stack(stack);
}

void	sort_three(t_stacks *arr)
{
	if (arr->a[0] > arr->a[1] && arr->a[0] > arr->a[2] && arr->a[1] > arr->a[2])
	{
		sa(arr);
		rra(arr);
	}
	else if (arr->a[0] > arr->a[1] && arr->a[0] > arr->a[2] && arr->a[1] < arr->a[2])
		ra(arr);
	else if (arr->a[0] > arr->a[1] && arr->a[0] < arr->a[2] && arr->a[1] < arr->a[2])
		sa(arr);
	else if (arr->a[0] < arr->a[1] && arr->a[0] > arr->a[2] && arr->a[1] > arr->a[2])
		rra(arr);
	else if (arr->a[0] < arr->a[1] && arr->a[0] < arr->a[2] && arr->a[1] > arr->a[2])
	{
		rra(arr);
		sa(arr);
	}
}

void	pick_sort(t_stacks *stack)
{
	if (stack->a_size == 2)
		sa(stack);
	else if (stack->a_size == 3)
		sort_three(stack);
	else
		radix_sort(stack);
}
