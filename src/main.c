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

#include "../inc/push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (argc < 2)
		exit (1);
	init_stacks(&stack, stack_size(argv));
	insert_stacks(argc, argv, &stack);
	is_valid_stack(&stack);
	pick_sort(&stack);
	free_stacks(&stack);
}
