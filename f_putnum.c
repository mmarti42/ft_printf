/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_putnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 08:51:18 by mmarti            #+#    #+#             */
/*   Updated: 2019/11/21 08:51:22 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

void	lenhandle(t_format *format, int len)
{
	int		tmp;
	char	a;

	a = ' ';
	if (format->fl.null && !format->fl.minus)
		a = '0';
	tmp = format->length;
	while (tmp-- > len)
		ft_putchar(a);
}

void	flhandle(t_format *format, int *len, t_res res)
{
	if (res.sign || format->fl.plus || format->fl.space)
		(*len)++;
	if (format->fl.null)
	{
		res.sign == 1 ? ft_putchar('-') : 0;
		if (format->fl.plus && res.sign == 0)
			ft_putchar('+');
		else if (format->fl.space && !res.sign)
			ft_putchar(' ');
	}
	if (*len < format->length && !format->fl.minus)
	{
		lenhandle(format, *len);
		*len = format->length;
	}
	if (!format->fl.null)
		res.sign == 1 ? ft_putchar('-') : 0;
	if (format->fl.plus && res.sign == 0 && !format->fl.null)
		ft_putchar('+');
	else if (format->fl.space && res.sign == 0 && !format->fl.null)
		ft_putchar(' ');
}

void	ft_putnum2(t_res res, int precision)
{
	while (*res.num && precision >= 0)
	{
		ft_putchar(*res.num++);
		precision--;
	}
	while (precision >= 0)
	{
		ft_putchar('0');
		precision--;
	}
}

int		ft_putnum(t_res res, int precision, t_format *format)
{
	int len;

	len = precision + res.entirelen;
	if (precision || format->fl.sharp)
		len++;
	flhandle(format, &len, res);
	while (*res.num != '.')
		ft_putchar(*res.num++);
	if (precision || format->fl.sharp)
		ft_putnum2(res, precision);
	if (format->fl.minus && format->length > len)
		lenhandle(format, len);
	return (len);
}
