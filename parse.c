/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:34:14 by mmarti            #+#    #+#             */
/*   Updated: 2019/11/21 11:34:16 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int	ft_parse_char(va_list vaptr, t_format *format)
{
	char c;

	c = va_arg(vaptr, int);
	return (ft_write_char((void *)&c, format));
}

int	ft_parse_string(va_list vaptr, t_format *format)
{
	char *str;

	str = va_arg(vaptr, char *);
	return (ft_write_s((void *)str, format));
}

int	ft_parse_int(va_list vaptr, t_format *format)
{
	long long a;

	if (format->mod.l)
		a = va_arg(vaptr, long);
	else if (format->mod.ll)
		a = va_arg(vaptr, long long);
	else
		a = va_arg(vaptr, int);
	return (ft_write_i((void *)&a, format));
}

int	ft_parse_other(va_list vaptr, t_format *format)
{
	long a;

	if (format->mod.l || format->type == 'p')
		a = va_arg(vaptr, long);
	else if (format->mod.ll)
		a = va_arg(vaptr, long long);
	else
		a = va_arg(vaptr, int);
	return (ft_write_u((void *)&a, format));
}

int	ft_parse(t_format *list, va_list vaptr)
{
	if (list->type == 's')
		return (ft_parse_string(vaptr, list));
	else if (list->type == 'c')
		return (ft_parse_char(vaptr, list));
	else if (list->type == 'd' || list->type == 'i')
		return (ft_parse_int(vaptr, list));
	else if (list->type == 'f')
		return (ft_parse_float(vaptr, list));
	else if (list->type == '%')
		return (ft_write_per(list));
	else
		return (ft_parse_other(vaptr, list));
}
