/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:42:06 by mmarti            #+#    #+#             */
/*   Updated: 2019/11/21 15:42:07 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

void	ft_uadd_o(int len, t_format *list)
{
	int		i;
	char	c;

	i = list->length - len;
	if (list->fl.minus != 1 && list->fl.null == 1)
		c = '0';
	else
		c = ' ';
	if (i > 0)
		ft_write_alot(i, c);
}

void	ft_write_o2(t_varo *var, t_format *list)
{
	if (var->number == 0 && list->precision != 0)
		var->len = var->len - list->fl.sharp;
	if (var->number == 0 && list->precision == 0)
		var->len = 0;
	if (list->precision > var->len + list->fl.sharp)
		var->per = list->precision;
	else
		var->per = var->len + list->fl.sharp;
	if (list->fl.null == 1 && list->fl.sharp == 1)
		write(1, "0", 1);
	if (list->fl.minus != 1)
		ft_uadd_o(var->per, list);
	if (list->fl.null != 1 && list->fl.sharp == 1)
		write(1, "0", 1);
	if (var->len - list->fl.sharp != 0)
		ft_write_alot((var->per - list->fl.sharp - var->len), '0');
	if (var->number == 0 && list->fl.sharp == 0 && list->precision != 0)
		write(1, "0", 1);
	if (var->per - list->fl.sharp != 0 &&
		list->precision != 0 && var->number != 0)
		ft_ulli(var->number, var->base, ft_upper(list), var->len);
	if (list->fl.minus == 1)
		ft_uadd_o(var->per, list);
}

int		ft_write_o(void *data, t_format *list)
{
	t_varo	var;

	if (list->precision != -1)
		list->fl.null = 0;
	var.ret = 0;
	write(1, list->prev, ft_strlen(list->prev));
	var.number = ft_un_i_reforge(data, list);
	var.base = 8;
	var.len = ft_ulli_lon_base(var.number, var.base);
	ft_write_o2(&var, list);
	write(1, list->post, ft_strlen(list->post));
	if (list->length > (var.per + var.ret))
		return (list->length + ft_strlen(list->prev) + ft_strlen(list->post));
	else
		return (var.per + var.ret +
				ft_strlen(list->prev) + ft_strlen(list->post));
}

int		ft_u_beg(void *data, t_format **l, unsigned long long int *n, int *per)
{
	int	len;

	if ((*l)->type != 'u')
		(*l)->fl.space = 0;
	if ((*l)->precision != -1)
		(*l)->fl.null = 0;
	write(1, (*l)->prev, ft_strlen((*l)->prev));
	*n = ft_un_i_reforge(data, (*l));
	len = ft_ulli_lon_base(*n, ft_base((*l)));
	if ((*l)->precision > len)
		*per = (*l)->precision;
	else
		*per = len;
	if ((*l)->precision == 0 && *n == 0)
		*per = 0;
	if (((*l)->fl.null == 1 || (*l)->fl.space == 1) && (*l)->type != 'u')
		ft_hash(*l, *n);
	return (len);
}

int		ft_write_u(void *data, t_format *list)
{
	int						len;
	int						ret;
	int						per;
	unsigned long long int	number;

	if (list->type == 'o')
		return (ft_write_o(data, list));
	len = ft_u_beg(data, &list, &number, &per);
	if (list->fl.minus != 1)
		ret = ft_uadd(per, list, number);
	if (list->fl.null != 1 && list->fl.space != 1 && list->type != 'u')
		ft_hash(list, number);
	if (per != len)
		ft_write_alot((per - len), '0');
	if (list->precision == 0 && number == 0)
		write(1, "", 0);
	else
		ft_ulli(number, ft_base(list), ft_upper(list), len);
	if (list->fl.minus == 1)
		ret = ft_uadd(per, list, number);
	write(1, list->post, ft_strlen(list->post));
	if (list->length > (per + ret))
		return (list->length + ft_strlen(list->prev) + ft_strlen(list->post));
	else
		return (per + ret + ft_strlen(list->prev) + ft_strlen(list->post));
}
