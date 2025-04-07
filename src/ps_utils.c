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
#include <unistd.h>
#include <limits.h>

void	err_exit(t_stacks *stack)
{
	write(2, "Error\n", 6);
	free_stacks(stack, 1);
}

void	safe_exit(t_stacks *stack, char **buffer)
{
	if (buffer)
		free_imp(buffer);
	err_exit(stack);
}

static long	atoi_convert_helper(char **buffer, char *str, t_stacks *stacks)
{
	long	num;

	num = 0;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			safe_exit(stacks, buffer);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

int	insert_atoi(char **buffer, char *str, t_stacks *stacks)
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
		safe_exit(stacks, buffer);
	while (*str == '0')
		str++;
	if (ft_strlen(str) > 11)
		safe_exit(stacks, buffer);
	num = atoi_convert_helper(buffer, str, stacks);
	if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
		err_exit(stacks);
	return ((int)num * sign);
}

void	swap(int *first, int *second)
{
	int	temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
