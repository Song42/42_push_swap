/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun42 <schaehun42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:03:04 by schaehun42        #+#    #+#             */
/*   Updated: 2022/08/03 20:37:31 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	set_min(t_stack **stack_a, int old_min)
{
	int			min;
	static int	int_min = 0;
	t_stack		*node;

	node = *stack_a;
	min = 2147483647;
	while (node)
	{
		if (node->content == -2147483648 && !int_min)
		{
			min = -2147483648;
			int_min = 1;
		}
		else if (min > node->content && (node->content > old_min))
			min = node->content;
		node = node->next;
	}
	return (min);
}

void	transform(t_stack **stack_a, int argc)
{
	int		i;
	int		old_min;
	t_stack	*new_stack;

	new_stack = ft_newstack(0);
	i = 0;
	while (++i < argc)
		ft_addstack_back(&new_stack, 0);
	i = -1;
	old_min = -2147483648;
	while (++i < argc)
	{
		old_min = set_min(stack_a, old_min);
		change_stack(stack_a, &new_stack, i, old_min);
	}
	free_stack(stack_a);
	*stack_a = new_stack;
}

void	find_max(t_stack **stack, int *max, int *bit_len)
{
	t_stack	*node_a;

	node_a = *stack;
	*max = -2147483648;
	while (node_a)
	{
		if (node_a->content > *max)
			*max = node_a->content;
		node_a = node_a->next;
	}
	*bit_len = 0;
	while ((*max >> *bit_len) != 0)
		++(*bit_len);
}
