/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insert_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:53:29 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/23 04:25:31 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../inc/push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	init_stacks(t_stacks *stacks, int size)
{
	if (size < 2)
		exit (1);
	stacks->a = malloc(sizeof(int) * size);
	if (!stacks->a)
		exit (1);
	stacks->b = malloc(sizeof(int) * size);
	if (!stacks->b)
	{
		free (stacks->a);
		exit (1);
	}
	stacks->a_size = 0;
	stacks->b_size = 0;
}

void	handle_string_arg(char *arg, t_stacks *stack)
{
	char			**split_buffer;
	unsigned int	i;

	split_buffer = ft_split(arg, ' ');
	if (!split_buffer)
		exit (1);
	i = 0;
	while (split_buffer[i])
	{
		stack->a[stack->a_size] = insert_atoi(split_buffer[i], stack);
		stack->a_size++;
		i++;
	}
	free_imp(split_buffer);
}

void	insert_stacks(int argc, char **arg, t_stacks *stack)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(arg[i], ' '))
		{
			handle_string_arg(arg[i], stack);
		}
		else
		{
			stack->a[stack->a_size] = insert_atoi(arg[i], stack);
			stack->a_size++;
		}
		i++;
	}
}

int	arg_size(char *arg)
{
	char	**split_buffer;
	int		i;

	i = 0;
	split_buffer = ft_split(arg, ' ');
	if (!split_buffer)
		exit(1);
	while (split_buffer[i])
		i++;
	free_imp(split_buffer);
	return (i);
}

int	stack_size(char **arg)
{
	unsigned int	i;
	int				stack_size;

	stack_size = 0;
	i = 1;
	while (arg[i])
	{
		if (arg[i][0] == '\0')
			exit(1);
		if (ft_strchr(arg[i], ' '))
			stack_size += arg_size(arg[i]);
		else
			stack_size++;
		i++;
	}
	return (stack_size);
}
