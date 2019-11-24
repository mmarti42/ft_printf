/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerenfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:51:20 by gerenfor          #+#    #+#             */
/*   Updated: 2019/11/20 22:09:18 by gerenfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int		ft_write_alot(int nom, char c)
{
	char	str[nom];
	int		i;

	i = 0;
	if (nom > 0)
	{
		while (i < nom)
		{
			str[i] = c;
			i++;
		}
		write(1, str, nom);
	}
	return (i);
}

int		ft_upper(t_format *list)
{
	if (list->type == 'X')
		return (1);
	return (0);
}

int		ft_base(t_format *list)
{
	if (list->type == 'o')
		return (8);
	if (list->type == 'x' || list->type == 'X' || list->type == 'p')
		return (16);
	if (list->type == 'u')
		return (10);
	if (list->type == 'b')
		return (2);
	write(1, "error", 5);
	return (10);
}

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
