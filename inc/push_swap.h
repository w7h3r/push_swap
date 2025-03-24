/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:41:57 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/22 02:04:25 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
}	t_stacks;

void	free_stacks(t_stacks *stack);
void	free_imp(char **str);
int		insert_atoi(char *str, t_stacks *stacks);
_Bool	stack_repeat(t_stacks *stack);
int		stack_sorted(t_stacks *stack);
void	is_valid_stack(t_stacks *stack);

void	init_stacks(t_stacks *stacks, int size);
void	handle_string_arg(char *arg, t_stacks *stack);
void	insert_stacks(int argc, char **arg, t_stacks *stack);
int		arg_size(char *arg);
int		stack_size(char **arg);

void	swap(int *first, int *second);
void	sa(t_stacks *stack);
void	sb(t_stacks *stack);
void	ss(t_stacks *stack);


#endif
