/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:41:57 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/17 03:33:21 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stacks {
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
}	t_stacks;

void	free_stacks(t_stacks *stack);
void	free_imp(char **str);
int	insert_atoi(char *str, t_stacks *stacks);

#endif
