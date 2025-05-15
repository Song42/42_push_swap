/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:42:19 by schaehun          #+#    #+#             */
/*   Updated: 2022/08/03 19:15:25 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

void		sa(t_stack **stack_a);
void		ra(t_stack **stack_a);
void		rra(t_stack **stack_a);
void		pa(t_stack **stack_a, t_stack **stack_b);

void		sb(t_stack **stack_b);
void		rb(t_stack **stack_b);
void		rrb(t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);

void		ss(t_stack **stack_a, t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

int			set_min(t_stack **stack_a, int old_min);
void		change_stack(t_stack **stack_a,
				t_stack **new_stack, int i, int min);
void		free_stack(t_stack **stack);
void		free_array(char **arr);

void		transform(t_stack **stack_a, int argc);
void		find_max(t_stack **stack, int *max, int *bit_len);
int			set_stack(int argc, char **argv,
				t_stack **stack_a, t_stack **stack_b);

void		sorts(int count, t_stack **stack_a, t_stack **stack_b);
void		sort_small(t_stack **stack_a);
void		sort_three(t_stack **stack_a);
void		sort_five_algo(t_stack **stack_a, t_stack **stack_b);
void		sort_five(t_stack **stack_a, t_stack **stack_b, int argc);
void		sort(t_stack **stack_a, t_stack **stack_b, int argc);

t_stack		*ft_newstack(int content);
void		ft_addstack_back(t_stack **stack, int content);
long long	ft_long_atoi(const char *nptr);
void		swaps(int *arr, t_stack **stack_a);

int			check_numbers(int argc, char **argv);
int			check_repeat(int argc, t_stack *stack_a);

void		error1(void);
void		error2(char **tab);
void		error3(t_stack **stack_a, t_stack **stack_b, char **arr);
void		error4(char **arr);

char		**arg_to_tab(char **argv, int *count);

int			sorted(t_stack **stack_a, int argc);
void		finish(t_stack **stack_a, t_stack **stack_b);

#endif
