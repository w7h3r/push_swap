/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 06:06:20 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/25 09:03:40 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <unistd.h>

void	sa(t_stacks *stack)
{
	swap(&stack->a[0], &stack->a[1]);
	write(1, "sa\n", 3);
}

void	sb(t_stacks *stack)
{
	swap(&stack->b[0], &stack->b[1]);
	write(1, "sb\n", 3);
}

void	ss(t_stacks *stack)
{
	swap(&stack->a[0], &stack->a[1]);
	swap(&stack->b[0], &stack->b[1]);
	write(1, "ss\n", 3);
}
