/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun42 <schaehun42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:03:15 by schaehun42        #+#    #+#             */
/*   Updated: 2022/08/03 19:14:26 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sorts(int count, t_stack **stack_a, t_stack **stack_b)
{
	if (count < 3)
		sort_small(stack_a);
	else if (count == 3)
		sort_three(stack_a);
	else if (count < 6)
		sort_five(stack_a, stack_b, count);
	else
		sort(stack_a, stack_b, count);
}

int	main(int argc, char *argv[])
{
	int		count;
	char	**tab;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		error1();
	tab = arg_to_tab(argv, &count);
	if (count == 0)
		error4(tab);
	if (check_numbers(count, tab))
		error2(tab);
	if (set_stack(count, tab, &stack_a, &stack_b) == -1)
		error3(&stack_a, &stack_b, tab);
	free_array(tab);
	if (!sorted(&stack_a, count))
		finish(&stack_a, &stack_b);
	sorts(count, &stack_a, &stack_b);
	finish(&stack_a, &stack_b);
	return (0);
}
