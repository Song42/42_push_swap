/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_commands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun42 <schaehun42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:03:23 by schaehun42        #+#    #+#             */
/*   Updated: 2022/07/26 14:03:24 by schaehun42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*node;
	t_stack	*new_last;
	t_stack	*first_node;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	node = *stack_a;
	first_node = node;
	new_last = (t_stack *) malloc(sizeof(t_stack));
	new_last->content = first_node->content;
	new_last->next = NULL;
	while (node->next)
		node = node->next;
	node->next = new_last;
	(*stack_a) = (*stack_a)->next;
	free(first_node);
	first_node = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_stack	*node;
	t_stack	*new_last;
	t_stack	*first_node;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	node = *stack_b;
	first_node = node;
	new_last = (t_stack *) malloc(sizeof(t_stack));
	new_last->content = first_node->content;
	new_last->next = NULL;
	while (node->next)
		node = node->next;
	node->next = new_last;
	(*stack_b) = (*stack_b)->next;
	free(first_node);
	first_node = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
