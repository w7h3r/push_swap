/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:41:51 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/27 01:32:57 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../lib/ft_printf/include/ft_printf.h"
#include "../inc/push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

void	print_stack(int *tab, int size, char *name)
{
	ft_printf("STACK %s: \n", name);
	for (int i = 0; i < size; i++)
		ft_printf("%d\n", tab[i]);
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
	pick_sort(&stack);

	print_stack(stack.a, stack.a_size, "A");
	print_stack(stack.b, stack.b_size, "B");
	print_stack(stack.idx_a, stack.a_size, "IDX");

	free_stacks(&stack);
}
