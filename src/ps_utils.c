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

void	err_exit(t_stacks *stack, const char *err_msg)
{
	write(2, "Error\n", 6);
	(void)err_msg;
	free_stacks(stack, 1);
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

static long	atoi_convert_helper(char *str, t_stacks *stacks)
{
	long	num;

	num = 0;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			err_exit(stacks, "Error: All arguments must be numeric");
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

int	insert_atoi(char *str, t_stacks *stacks)
{
	long		num;
	int			sign;

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
	if (ft_strlen(str) == 0)
		err_exit(stacks, "Error: Must be a number after sign");
	while (*str == '0')
		str++;
	if (ft_strlen(str) > 11)
		err_exit(stacks, "Error: All numbers must be at integer range");
	num = atoi_convert_helper(str, stacks);
	if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
		err_exit(stacks, "Error: All arguments must be at integer range!");
	return ((int)num * sign);
}

void	swap(int *first, int *second)
{
	int	temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
