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

#include "../lib/libft/libft.h"
#include "../inc/push_swap.h"
#include <unistd.h>
#include <stdlib.h>

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
	{
		err_exit(stack, "Error: All arguments must be uniqe integers");
		exit (1);
	}
	if (stack_sorted(stack))
	{
		err_exit(stack, "Error: Agruments already sorted");
		exit (1);
	}
}
