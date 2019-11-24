/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:48:58 by mmarti            #+#    #+#             */
/*   Updated: 2019/11/21 11:48:59 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char		*get_flags(t_flags *fl, char *str)
{
	static char flag_list[5] = {'0', '-', '#', '+', ' '};

	while (ft_strchr(flag_list, *str))
	{
		if (*str == '0')
			fl->null = 1;
		else if (*str == '-')
			fl->minus = 1;
		else if (*str == '#')
			fl->sharp = 1;
		else if (*str == '+')
			fl->plus = 1;
		else if (*str == ' ')
			fl->space = 1;
		str++;
	}
	return (str);
}

char		*get_length(t_format *list, char *s)
{
	char *tmp;
	char *len;

	tmp = s;
	while (*s && *s >= '0' && *s <= '9')
		s++;
	len = ft_strsub(tmp, 0, s - tmp);
	list->length = ft_atoi(len);
	free(len);
	return (s);
}

char		*get_precision(t_format *list, char *s)
{
	char *tmp;
	char *precision;

	if (*s != '.')
		return (s);
	s++;
	tmp = s;
	while (*s && *s >= '0' && *s <= '9')
		s++;
	precision = ft_strsub(tmp, 0, s - tmp);
	list->precision = ft_atoi(precision);
	free(precision);
	return (s);
}

t_format	*handle_format(t_format *list, char *str)
{
	char	*s;
	int		i;

	s = ft_strchr(str, '%');
	i = s - str;
	list->prev = ft_strsub(str, 0, i);
	s = get_flags(&list->fl, s + 1);
	s = get_length(list, s);
	s = get_precision(list, s);
	s = get_mod(list, s);
	list->type = *s;
	list->post = ft_strcdup(++s, '%');
	s += ft_strlen(list->post);
	if (*s)
		fladd(s, list);
	return (list);
}

t_format	*fladd(char *format, t_format *list)
{
	t_format *cur;

	cur = get_last_format(list);
	if (!cur)
	{
		list = new_format();
		cur = list;
	}
	else
	{
		cur->next = new_format();
		cur = cur->next;
	}
	handle_format(cur, format);
	return (list);
}
