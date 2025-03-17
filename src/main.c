/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:41:51 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/17 07:12:19 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../inc/push_swap.h"
#include <stdlib.h>

void	init_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->a_size = 0;
	stacks->a_size = 0;
}

int	insert_atoi()
{
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

void	insert_stacks(int argc, char **arg, t_stacks stack)
{
	char	**split_buffer;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (ft_strchr(arg[i], ' '))
		{
			while (1)
			{
				split_buffer = ft_split(arg[i], ' ');
				if (!split_buffer)
					break ;

			}
		}
		else
		{
			stack.a[stack.a_size] = insert_atoi();
			stack.a_size++;
		}
		i++;
	}
}

// DONT FORGET TO MALLOC STACKS!!!!

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (argc < 2)
		exit(1);
	init_stacks(&stack);
	insert_stacks(argc, &argv[1], stack);
}
