/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_commands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun42 <schaehun42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:03:09 by schaehun42        #+#    #+#             */
/*   Updated: 2022/08/01 15:59:28 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	t_stack	*new_front;

	if ((*stack_b) == NULL)
		return ;
	node = *stack_b;
	new_front = (t_stack *) malloc(sizeof(t_stack));
	new_front->content = (*stack_b)->content;
	new_front->next = (*stack_a);
	*stack_a = new_front;
	*stack_b = (*stack_b)->next;
	free(node);
	node = NULL;
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	t_stack	*new_front;

	if ((*stack_a) == NULL)
		return ;
	node = *stack_a;
	new_front = (t_stack *) malloc(sizeof(t_stack));
	new_front->content = (*stack_a)->content;
	new_front->next = (*stack_b);
	*stack_b = new_front;
	*stack_a = (*stack_a)->next;
	free(node);
	node = NULL;
	write(1, "pb\n", 3);
}
