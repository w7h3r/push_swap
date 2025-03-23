/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:41:51 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/22 02:05:27 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../inc/push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
void	print_stack(int *tab, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d\n", tab[i]);
}
*/

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (argc < 2)
		exit(1);
	init_stacks(&stack, stack_size(argv));
	insert_stacks(argc, argv, &stack);
	is_valid_stack(&stack);
	free_stacks(&stack);
}
