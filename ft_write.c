/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerenfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:56:51 by gerenfor          #+#    #+#             */
/*   Updated: 2019/11/21 00:05:33 by gerenfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int		ft_write_s(void *data, t_format *list)
{
	int	len_s;
	int	i;

	if (data == NULL)
		data = "(null)";
	if (data == NULL)
		len_s = 6;
	if (data != NULL)
		len_s = ft_strlen((char *)data);
	if (list->precision != -1 && len_s > list->precision)
		len_s = list->precision;
	i = 0;
	write(1, list->prev, ft_strlen(list->prev));
	if (list->length > len_s && list->fl.minus == 0 && list->fl.null == 1)
		i = ft_write_alot(list->length - len_s, '0');
	else if (list->length > len_s && list->fl.minus == 0 && list->fl.null != 1)
		i = ft_write_alot(list->length - len_s, ' ');
	write(1, (char *)data, len_s);
	if (list->length > len_s && list->fl.minus == 1)
		i = ft_write_alot(list->length - len_s, ' ');
	write(1, list->post, ft_strlen(list->post));
	return (ft_strlen(list->prev) + i + len_s + ft_strlen(list->post));
}

int		ft_i_beg(void *data, t_format **list, long long int *number, int *nega)
{
	if ((*list)->precision != -1)
		(*list)->fl.null = 0;
	if ((*list)->fl.minus == 1)
		(*list)->fl.null = 0;
	if ((*list)->fl.plus == 1)
		(*list)->fl.space = 0;
	write(1, (*list)->prev, ft_strlen((*list)->prev));
	*number = ft_int_reforge(data, (*list), nega);
	return (ft_int_lon_base(*number, 10));
}

void	ft_i_fin(t_format *list, long long int number, int *nega, int per)
{
	int len;

	len = ft_int_lon_base(number, 10);
	if (list->precision != 0 || number != 0)
		ft_print_lli_base(number, 10, 0, len);
	if (list->fl.minus == 1)
		ft_add(per, *nega, list);
	write(1, list->post, ft_strlen(list->post));
	if (list->fl.plus == 1 || list->fl.space == 1)
		*nega = 1;
}

int		ft_write_i(void *data, t_format *list)
{
	int				nega;
	int				len;
	int				per;
	long long int	number;

	len = ft_i_beg(data, &list, &number, &nega);
	if (list->precision > len)
		per = list->precision;
	else
		per = len;
	if (list->precision == 0 && number == 0)
		per = 0;
	if (list->fl.minus == 1 || list->fl.null == 1)
		ft_sign(nega, list);
	if (list->fl.minus != 1)
		ft_add(per, nega, list);
	if (list->fl.minus == 0 && list->fl.null != 1)
		ft_sign(nega, list);
	ft_write_alot(per - len, '0');
	ft_i_fin(list, number, &nega, per);
	if (list->length > (per + nega))
		return (list->length + ft_strlen(list->prev) + ft_strlen(list->post));
	else
		return (per + nega + ft_strlen(list->prev) + ft_strlen(list->post));
}

int		ft_write_per(t_format *list)
{
	int						len;
	unsigned long long int	number;
	int						ret;

	number = 0;
	list->type = '%';
	ret = 0;
	write(1, list->prev, ft_strlen(list->prev));
	len = 1;
	if (list->fl.minus != 1)
		ret = ft_uadd(len, list, number);
	write(1, "%", 1);
	if (list->fl.minus == 1)
		ret = ft_uadd(len, list, number);
	write(1, list->post, ft_strlen(list->post));
	if (list->length > (len + ret))
		return (list->length + ft_strlen(list->prev) + ft_strlen(list->post));
	else
		return (len + ret + ft_strlen(list->prev) + ft_strlen(list->post));
}
