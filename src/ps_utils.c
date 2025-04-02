/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 03:26:03 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/17 03:26:07 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../lib/ft_printf/include/ft_printf.h"
#include "../inc/push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

void	err_exit(t_stacks *stack, const char *err_msg)
{
	ft_printf("%s\n", err_msg);
	free_stacks(stack);
}

void	free_stacks(t_stacks *stack)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack->idx_a)
		free(stack->idx_a);
	exit (1);
}

void	free_imp(char **str)
{
	int	i;

	if (!*str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	insert_atoi(char *str, t_stacks *stacks)
{
	long		num;
	short int	sign;

	sign = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			err_exit(stacks, "Error: All arguments must be numeric");
		num = num * 10 + (*str - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			err_exit(stacks, "Error: All arguments must be at integer range!");
		str++;
	}
	return ((int)num * sign);
}

void	swap(int *first, int *second)
{
	int	temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
