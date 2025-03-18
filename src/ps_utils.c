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
#include "../inc/push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

void	free_stacks(t_stacks *stack)
{
	free(stack->a);
	free(stack->b);
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
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (num > INT_MAX || num < INT_MIN)
			free_stacks(stacks);
		str++;
	}
	return ((int)num * sign);
}

