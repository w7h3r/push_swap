/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 08:38:29 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/25 09:08:15 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	sort_arr(int *arr, int arr_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_size - 1)
	{
		j = i + 1;
		while (j < arr_size)
		{
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
}

void	index_arr(int *arr, int arr_size)
{
	int	i;

	i = 0;
	while (i < arr_size)
	{
		arr[i] = i;
		i++;
	}
}

void	index_stack(t_stacks *stack)
{
	int	*indexed_stack;
	int	i;

	indexed_stack = malloc(sizeof(int) * stack->a_size);
	if (!indexed_stack)
	{
		free_stacks(stack);
		exit (1);
	}
	i = 0;
	while (i < stack->a_size)
	{
		indexed_stack[i] = stack->a[i];
		i++;
	}
	sort_arr(indexed_stack, stack->a_size);
	index_arr(indexed_stack, stack->a_size);
	for (int i = 0; i < 4; i++)
		printf("%d\n", indexed_stack[i]);
	free (indexed_stack);
}
