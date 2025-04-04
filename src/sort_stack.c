/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:28:31 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/03 23:22:07 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>
#include <unistd.h>

void	sort_three(t_stacks *arr)
{
	if (arr->a[0] > arr->a[1] && arr->a[0] > arr->a[2] && arr->a[1] > arr->a[2])
	{
		sa(arr);
		rra(arr);
	}
	else if (arr->a[0] > arr->a[1] && \
			arr->a[0] > arr->a[2] && arr->a[1] < arr->a[2])
		ra(arr);
	else if (arr->a[0] > arr->a[1] && \
			arr->a[0] < arr->a[2] && arr->a[1] < arr->a[2])
		sa(arr);
	else if (arr->a[0] < arr->a[1] && \
			arr->a[0] > arr->a[2] && arr->a[1] > arr->a[2])
		rra(arr);
	else if (arr->a[0] < arr->a[1] && \
			arr->a[0] < arr->a[2] && arr->a[1] > arr->a[2])
	{
		rra(arr);
		sa(arr);
	}
}

int	find_min_idx(t_stacks *stack)
{
	int	min_idx;
	int	min;
	int	i;

	min = stack->a[0];
	min_idx = 0;
	i = 0;
	while (i < stack->a_size)
	{
		if (stack->a[i] < min)
		{
			min = stack->a[i];
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

void	min_to_top(t_stacks *stack)
{
	int	min_idx;

	min_idx = find_min_idx(stack);
	if (min_idx <= stack->a_size / 2)
		while (min_idx--)
			ra(stack);
	else
		while (min_idx++ < stack->a_size)
			rra(stack);
}

void	sort_less_ten_arg(t_stacks *stack)
{
	while (stack->a_size > 3)
	{
		min_to_top(stack);
		pb(stack);
	}
	sort_three(stack);
	while (stack->b_size)
		pa(stack);
}

void	pick_sort(t_stacks *stack)
{
	if (stack->a_size == 2)
		sa(stack);
	else if (stack->a_size == 3)
		sort_three(stack);
	else if (stack->a_size >= 4 && stack->a_size < 10)
		sort_less_ten_arg(stack);
	else
		radix_sort(stack);
}
