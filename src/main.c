/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:41:51 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/23 04:26:21 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../inc/push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>
void	print_stack(int *tab, int size, char *name)
{
	printf("STACK %s: \n", name);
	for (int i = 0; i < size; i++)
		printf("%d\n", tab[i]);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (argc < 2)
		exit(1);
	init_stacks(&stack, stack_size(argv));
	insert_stacks(argc, argv, &stack);
	is_valid_stack(&stack);
//	sa(&stack);
	pb(&stack);
	pb(&stack);
	print_stack(stack.a, stack.a_size, "A");
	print_stack(stack.b, stack.b_size, "B");
	free_stacks(&stack);
}
