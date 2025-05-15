/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:01:58 by schaehun          #+#    #+#             */
/*   Updated: 2022/08/01 16:26:13 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	**arg_to_tab(char **argv, int *count)
{
	int		i;
	char	*temp;
	char	*str;
	char	**arg;

	str = malloc(sizeof(str));
	str[0] = 0;
	i = 1;
	while (argv[i])
	{
		temp = ft_strjoin(str, argv[i]);
		free(str);
		str = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	arg = ft_split(str, ' ');
	free(str);
	i = -1;
	*count = 0;
	while (arg[++i])
		(*count)++;
	return (arg);
}
