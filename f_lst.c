/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lst.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 09:41:02 by mmarti            #+#    #+#             */
/*   Updated: 2019/11/21 09:41:03 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

void		ft_free_pow(t_pow *lst)
{
	t_pow *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->num);
		free(tmp);
	}
}

void		ft_free_format(t_format *lst)
{
	t_format *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->post);
		free(tmp->prev);
		free(tmp);
	}
}

void		ft_free_vars(t_vars vars)
{
	if (vars.entire)
		ft_free_pow(vars.entire);
	if (vars.frac)
		ft_free_pow(vars.frac);
}

t_format	*new_format(void)
{
	t_format *list;

	if (!(list = (t_format *)ft_memalloc(sizeof(t_format))))
		exit(123);
	list->precision = -1;
	list->length = -1;
	return (list);
}
