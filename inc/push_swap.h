/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:41:57 by muokcan           #+#    #+#             */
/*   Updated: 2025/03/25 09:00:55 by muokcan          ###   ########.fr       */
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
	int	target_a;
	int	target_b;
	int	cost;
}	t_stacks;

void	free_stacks(t_stacks *stack);
void	free_imp(char **str);
int		insert_atoi(char *str, t_stacks *stacks);
_Bool	stack_repeat(t_stacks *stack);
int		stack_sorted(t_stacks *stack);
void	is_valid_stack(t_stacks *stack);
void	err_exit(t_stacks *stack, const char *err_msg);

void	init_stacks(t_stacks *stacks, int size);
void	handle_string_arg(char *arg, t_stacks *stack);
void	insert_stacks(int argc, char **arg, t_stacks *stack);
int		arg_size(char *arg);
int		stack_size(char **arg);

void	swap(int *first, int *second);
void	sa(t_stacks *stack);
void	sb(t_stacks *stack);
void	ss(t_stacks *stack);
void	push_to_stack(int *src, int *dst, int *src_size, int *dst_size);
void	pa(t_stacks *stack);
void	pb(t_stacks *stack);
void	rotate_stack(int *stack, int *size);
void	ra(t_stacks *stack);
void	rb(t_stacks *stack);
void	rr(t_stacks *stack);
void	rev_rotate_stack(int *stack, int *size);
void	rra(t_stacks *stack);
void	rrb(t_stacks *stack);
void	rrr(t_stacks *stack);

void	pick_sort(t_stacks *stack);
void	sort_three(t_stacks *arr);

#endif
