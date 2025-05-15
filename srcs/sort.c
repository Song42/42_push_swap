/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun42 <schaehun42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:03:51 by schaehun42        #+#    #+#             */
/*   Updated: 2022/08/01 16:16:37 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_small(t_stack **stack_a)
{
	if ((*stack_a)->next)
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	int		i;
	int		arr[3];
	t_stack	*node;

	node = *stack_a;
	i = 0;
	while (node)
	{
		arr[i] = node->content;
		i++;
		node = node->next;
	}
	if (i < 2)
		return ;
	if (i < 3)
	{
		if (arr[0] < arr[1])
			return ;
		else
			sa(stack_a);
		return ;
	}
	swaps(arr, stack_a);
}

void	sort_five_algo(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->content == 4 || (*stack_b)->content == 0)
		pa(stack_a, stack_b);
	while (*stack_b)
	{
		if ((*stack_b)->content + 1 == (*stack_a)->content)
			pa(stack_a, stack_b);
		else if ((*stack_b)->content - 1 == (*stack_a)->content)
		{
			ra(stack_a);
			pa(stack_a, stack_b);
		}
		else
		{
			if ((*stack_b)->content < (*stack_a)->content)
				rra(stack_a);
			else
				ra(stack_a);
		}
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int		pos;
	t_stack	*node_a;

	if (argc == 5)
		pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	sort_five_algo(stack_a, stack_b);
	pos = 0;
	node_a = *stack_a;
	while (node_a)
	{
		if (node_a->content == 0)
			break ;
		++pos;
		node_a = node_a->next;
	}
	while ((*stack_a)->content != 0)
	{
		if (pos > 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
	return ;
}

void	sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int		max;
	int		bit_len;
	int		i;
	int		j;

	find_max(stack_a, &max, &bit_len);
	i = 0;
	while (i < bit_len)
	{
		j = 0;
		while (j < argc)
		{
			if ((((*stack_a)->content >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
	while (*stack_b)
		pa(stack_a, stack_b);
	return ;
}
