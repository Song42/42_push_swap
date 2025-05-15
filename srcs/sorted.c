/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:06:15 by schaehun          #+#    #+#             */
/*   Updated: 2022/08/01 16:27:59 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sorted(t_stack **stack_a, int argc)
{
	int		i;
	t_stack	*node_a;

	i = 0;
	node_a = *stack_a;
	while (i < argc)
	{
		if (node_a->content == i)
			node_a = node_a->next;
		else
			return (1);
		i++;
	}
	return (0);
}

void	finish(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	exit(0);
}
