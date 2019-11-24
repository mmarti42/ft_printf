/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:18:41 by mmarti            #+#    #+#             */
/*   Updated: 2019/10/21 17:18:42 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char		*skip_mod(char *s)
{
	static char mod[3] = {'l', 'h', 'L'};

	while (ft_strchr(mod, *s))
		s++;
	return (s);
}

char		*get_mod(t_format *list, char *s)
{
	if (!*s)
		return (s);
	if (!(ft_strncmp(s, "ll", 2)))
		list->mod.ll = 1;
	else if (!(ft_strncmp(s, "hh", 2)))
		list->mod.hh = 1;
	else if (*s == 'h')
		list->mod.h = 1;
	else if (ft_strnchr(s, 'l', 2) || !ft_strncmp(s, "LL", 2))
		list->mod.l = 1;
	else if (*s == 'L')
		list->mod.lb = 1;
	return (skip_mod(s));
}

t_format	*get_last_format(t_format *list)
{
	if (!list)
		return (0);
	while (list->next)
		list = list->next;
	return (list);
}

int			parse_start(t_format *list, va_list vaptr)
{
	int a;

	a = 0;
	while (list)
	{
		if (!list->type)
		{
			a += 6;
			ft_putstr("error");
			break ;
		}
		a += ft_parse(list, vaptr);
		list = list->next;
	}
	return (a);
}

int			ft_printf(char *format, ...)
{
	t_format	*list;
	t_format	*tmp;
	va_list		vaptr;
	int			a;

	list = 0;
	if (!ft_strchr(format, '%'))
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	list = fladd(format, list);
	tmp = list;
	va_start(vaptr, format);
	a = parse_start(list, vaptr);
	va_end(vaptr);
	ft_free_format(tmp);
	return (a);
}
