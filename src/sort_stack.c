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

int	find_min(int *arr, int size)
{
	int	i;
	int	min;

	min = arr[0];
	i = -1;
	while (++i < size)
		if (min > arr[i])
			min = arr[i];
	return (min);
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
}
