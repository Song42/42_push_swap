/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun42 <schaehun42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:03:26 by schaehun42        #+#    #+#             */
/*   Updated: 2022/08/03 19:14:46 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*node;
	t_stack	*last_node;
	t_stack	*new_front;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	node = *stack_a;
	while (node->next)
	{
		if (node->next->next == NULL)
		{
			last_node = node->next;
			new_front = (t_stack *) malloc(sizeof(t_stack));
			new_front->content = last_node->content;
			node->next = NULL;
			free(last_node);
			last_node = NULL;
			new_front->next = *stack_a;
			*stack_a = new_front;
			write(1, "rra\n", 4);
			return ;
		}
		node = node->next;
	}
}

void	rrb(t_stack **stack_b)
{
	t_stack	*node;
	t_stack	*last_node;
	t_stack	*new_front;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	node = *stack_b;
	while (node->next)
	{
		if (node->next->next == NULL)
		{
			last_node = node->next;
			new_front = (t_stack *) malloc(sizeof(t_stack));
			new_front->content = last_node->content;
			node->next = NULL;
			free(last_node);
			last_node = NULL;
			new_front->next = *stack_b;
			*stack_b = new_front;
			write(1, "rrb\n", 4);
			return ;
		}
		node = node->next;
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
