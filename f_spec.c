/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:47:52 by mmarti            #+#    #+#             */
/*   Updated: 2019/11/21 15:47:54 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char	*check(char *str)
{
	static char *inf = "1111111111111111";

	if (!strncmp(inf, str + 1, 15))
	{
		if (*(str + 16) == '1' && !ft_strchr(str + 17, '1'))
			return ("inf");
		else
			return ("nan");
	}
	return (0);
}

void	handle_w_spec(t_format *format, int len)
{
	int		tmp;
	char	a;

	a = ' ';
	tmp = format->length;
	while (tmp-- > len)
		ft_putchar(a);
}

void	handle_fl_spec(t_format *format, char c, int *len)
{
	if (c || format->fl.plus || format->fl.space)
		(*len)++;
	if (format->length < *len || format->fl.minus)
		c ? ft_putchar('-') : 0;
	if (format->fl.space && !c)
		ft_putchar(' ');
	if (*len < format->length && !format->fl.minus)
	{
		handle_w_spec(format, *len);
		c ? ft_putchar('-') : 0;
		*len = format->length;
	}
}
