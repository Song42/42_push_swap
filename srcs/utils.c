/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun42 <schaehun42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:03:54 by schaehun42        #+#    #+#             */
/*   Updated: 2022/08/03 22:56:58 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_newstack(int content)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (0);
	list->content = content;
	list->next = 0;
	return (list);
}

void	ft_addstack_back(t_stack **stack, int content)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = ft_newstack(content);
}

long long	ft_long_atoi(const char *nptr)
{
	int			i;
	long long	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (nptr[i] == '+' && sign == 1)
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		num = num * 10 + (nptr[i++] - '0');
		if (num > 2148493637 && sign == 1)
			return (2147483648);
		if (num > 2147483648 && sign == -1)
			return (-2147483649);
	}
	return (num * sign);
}

void	swaps(int *arr, t_stack **stack_a)
{
	if ((arr[0] < arr[1]) && (arr[1] < arr[2]))
		return ;
	if ((arr[0] < arr[1]) && (arr[1] > arr[2]) && (arr[0] < arr[2]))
	{
		rra(stack_a);
		sa(stack_a);
	}
	if ((arr[0] < arr[1]) && (arr[1] > arr[2]) && (arr[0] > arr[2]))
	{
		rra(stack_a);
	}
	if ((arr[0] > arr[1]) && (arr[1] < arr[2]) && (arr[0] < arr[2]))
	{
		sa(stack_a);
	}
	if ((arr[0] > arr[1]) && (arr[1] < arr[2]) && (arr[0] > arr[2]))
	{
		ra(stack_a);
	}
	if ((arr[0] > arr[1]) && (arr[1] > arr[2]) && (arr[0] > arr[2]))
	{
		ra(stack_a);
		sa(stack_a);
	}
}
