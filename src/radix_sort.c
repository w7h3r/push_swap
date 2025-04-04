/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:48:59 by muokcan           #+#    #+#             */
/*   Updated: 2025/04/04 03:06:36 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../inc/push_swap.h"
#include "../lib/ft_printf/include/ft_printf.h"
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

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

void	index_stack(t_stacks *stack, int *temp_idx)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->a_size)
	{
		j = 0;
		while (j < stack->a_size)
		{
			if (stack->a[i] == stack->idx_a[j])
			{
				temp_idx[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
	copy_stacks(temp_idx, stack->a, stack->a_size);
}

int	compute_max_bit_count(int *arr, int size)
{
	int	bit_count;
	int	max;
	int	i;

	max = arr[0];
	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
//	ft_printf("\nMAX INT: %d\n", max);
	bit_count = 0;
	while (max >> bit_count)
		bit_count++;
	return (bit_count);
}

void	sort_indexed_stack(t_stacks *stack)
{
	int	max_bit;
	int	size;
	int	bit;
	int	i;

	bit = 0;
	max_bit = compute_max_bit_count(stack->a, stack->a_size);
//	ft_printf("MAX BIT: %d\n", max_bit);
	while (bit < max_bit)
	{
		size = stack->a_size;
		i = 0;
		while (i < size)
		{
			if ((stack->a[0] >> bit) & 1)
				ra(stack);
			else
				pb(stack);
			i++;
		}
		while (stack->b_size)
			pa(stack);
		bit++;
	}
}

void	radix_sort(t_stacks *stack)
{
	int	*temp_idx;

	bubble_sort_stack(stack);
	temp_idx = malloc(sizeof(int) * stack->a_size);
	if (!temp_idx)
		err_exit(stack, "Error: Malloc failed: radix_sort()");
	index_stack(stack, temp_idx);
	free (temp_idx);
	sort_indexed_stack(stack);
}
