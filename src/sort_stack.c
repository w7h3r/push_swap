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

void	sort_three(t_stacks *stack)
{
	// 1 2 3
	if (stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2])
		return ;
	// 3 2 1
	else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		sa(stack);
		rra(stack);
	}
	// 3 1 2
	else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2])
		ra(stack);
	else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2])
}

void	pick_sort(t_stacks *stack)
{
	if (stack->a_size == 2)
		sa(stack);
	else if (stack->a_size == 3)
		sort_three(stack);
}
