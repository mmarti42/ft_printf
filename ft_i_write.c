/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerenfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:22:27 by gerenfor          #+#    #+#             */
/*   Updated: 2019/11/20 21:27:36 by gerenfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

long long int	ft_int_reforge(void *data, t_format *list, int *nega)
{
	long long int	number;

	if (list->mod.h == 1)
		number = (long long)*((short int*)data);
	else if (list->mod.l == 1)
		number = (long long)*((long int*)data);
	else if (list->mod.hh == 1)
		number = (long long)*((char*)data);
	else if (list->mod.ll == 1)
		number = (long long)*((long long int*)data);
	else
		number = (long long)*((int*)data);
	if (number < 0)
		*nega = 1;
	else
		*nega = 0;
	return (number);
}

int				ft_int_lon_base(long long int nom, int base)
{
	int	len;

	len = 0;
	if (base == 0)
		return (0);
	if (nom == 0)
		return (1);
	while (nom <= -base || nom >= base)
	{
		nom = nom / base;
		len++;
	}
	return (len + 1);
}

void			ft_print_lli_base(long long int num, int base, int up, int nom)
{
	char			str[nom];
	long long int	obj;
	int				i;
	char			res;

	i = nom - 1;
	obj = num;
	while (i >= 0)
	{
		res = obj % base;
		if (res < 0)
			res = -1 * res;
		if (res < 10)
			res = res + 48;
		else
			res = res + 97 - 10 - (32 * up);
		*(str + i) = res;
		if (obj >= base)
			obj = obj / base;
		if (obj <= -base)
			obj = obj / (-base);
		i--;
	}
	write(1, str, nom);
}

void			ft_sign(int nega, t_format *list)
{
	if (nega == 1)
		write(1, "-", 1);
	else if (list->fl.plus == 1)
		write(1, "+", 1);
	else if (list->fl.space == 1)
		write(1, " ", 1);
}

void			ft_add(int len, int nega, t_format *list)
{
	int		i;
	char	c;

	if (list->fl.minus != 1 && list->fl.null == 1 && list->precision == -1)
		c = '0';
	else
		c = ' ';
	i = list->length - len;
	if (list->fl.plus == 1 || list->fl.space == 1 || nega == 1)
		i--;
	if (i > 0)
	{
		ft_write_alot(i, c);
	}
}
