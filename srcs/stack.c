/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:29:33 by schaehun          #+#    #+#             */
/*   Updated: 2022/08/03 20:34:52 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	change_stack(t_stack **stack_a, t_stack **new_stack, int i, int min)
{
	t_stack	*node;
	t_stack	*new_node;

	node = *stack_a;
	new_node = *new_stack;
	while (new_node)
	{
		if (node->content == min)
			new_node->content = i;
		node = node->next;
		new_node = new_node->next;
	}
}

int	set_stack(int argc, char **argv, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	*stack_a = ft_newstack(ft_atoi(argv[i++]));
	*stack_b = NULL;
	while (i < argc)
		ft_addstack_back(stack_a, ft_atoi(argv[i++]));
	transform(stack_a, argc);
	if (check_repeat(argc, *stack_a))
		return (-1);
	return (0);
}
