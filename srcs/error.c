/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:29:39 by schaehun          #+#    #+#             */
/*   Updated: 2022/08/01 16:21:16 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error1(void)
{
	write(2, "Usage: ./push_swap [argv]\n", 26);
	exit(1);
}

void	error2(char **arr)
{
	free_array(arr);
	write(2, "InputError: wrong argument\n", 27);
	exit(2);
}

void	error3(t_stack **stack_a, t_stack **stack_b, char **arr)
{
	free_array(arr);
	free_stack(stack_a);
	free_stack(stack_b);
	write(2, "InputError: repetitive argument\n", 32);
	exit(3);
}

void	error4(char **arr)
{
	free_array(arr);
	write(2, "InputError: empty input?\n", 25);
	exit(4);
}
