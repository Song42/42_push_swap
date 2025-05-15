/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun42 <schaehun42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:02:57 by schaehun42        #+#    #+#             */
/*   Updated: 2022/08/03 22:57:12 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_numbers(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;
	int	check;

	i = -1;
	while (++i < argc)
	{
		len = ft_strlen(argv[i]);
		j = 0;
		check = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			++j;
		while (j < len)
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			check = 1;
			++j;
		}
		if ((ft_long_atoi(argv[i]) > 2147483647
				|| ft_long_atoi(argv[i]) < -2147483648) || !check)
			return (-1);
	}
	return (0);
}

int	check_repeat(int argc, t_stack *stack_a)
{
	int		i;
	int		*arr;
	t_stack	*node_a;

	arr = malloc(sizeof(int) * (argc));
	i = -1;
	while (++i < argc)
		arr[i] = 0;
	i = -1;
	node_a = stack_a;
	while (++i < argc)
	{
		if (arr[node_a->content] != 1)
			arr[node_a->content] = 1;
		else
		{
			free(arr);
			return (1);
		}
		node_a = node_a->next;
	}
	free(arr);
	return (0);
}
