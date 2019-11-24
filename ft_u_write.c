/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerenfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:42:20 by gerenfor          #+#    #+#             */
/*   Updated: 2019/11/20 23:15:43 by gerenfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

unsigned long long int	ft_un_i_reforge(void *data, t_format *list)
{
	unsigned long long	int number;

	if (list->type == 'p')
		number = (unsigned long long)*((long int*)data);
	else if (list->mod.h == 1)
		number = (unsigned long long)*((unsigned short int*)data);
	else if (list->mod.l == 1)
		number = (unsigned long long)*((unsigned long int*)data);
	else if (list->mod.hh == 1)
		number = (unsigned long long)*((unsigned char*)data);
	else if (list->mod.ll == 1)
		number = (unsigned long long)*((unsigned long long int*)data);
	else
		number = (unsigned long long)*((unsigned int*)data);
	return (number);
}

int						ft_ulli_lon_base(unsigned long long int nom, int base)
{
	int	len;

	len = 0;
	if (base == 0)
		return (0);
	if (nom == 0)
		return (1);
	while (nom >= (unsigned int)base)
	{
		nom = nom / base;
		len++;
	}
	return (len + 1);
}

void					ft_ulli(unsigned long long int n, int b, int u, int nom)
{
	char					str[nom];
	unsigned long long int	obj;
	int						i;
	char					res;

	i = nom - 1;
	obj = n;
	while (i >= 0)
	{
		res = obj % b;
		if (res < 10)
			res = res + 48;
		else
			res = res + 97 - 10 - (32 * u);
		*(str + i) = res;
		if (obj >= (unsigned int)b)
			obj = obj / b;
		i--;
	}
	write(1, str, nom);
}

void					ft_hash(t_format *list, unsigned long long int number)
{
	if (list->fl.sharp == 1 && number != 0)
	{
		if (list->type == 'o')
			write(1, "0", 1);
		if (list->type == 'x' || list->type == 'p')
			write(1, "0x", 2);
		if (list->type == 'X')
			write(1, "0X", 2);
	}
	if (list->type == 'p')
		write(1, "0x", 2);
}

int						ft_uadd(int l, t_format *list, unsigned long long int n)
{
	int		i;
	char	c;
	int		mem;

	mem = 0;
	if (list->fl.minus != 1 && list->fl.null == 1)
		c = '0';
	else
		c = ' ';
	if (list->fl.sharp == 1 && n != 0)
	{
		if (list->type == 'o')
			mem++;
		if (list->type == 'x' || list->type == 'X')
			mem = mem + 2;
	}
	if (list->type == 'p')
		mem = mem + 2;
	if (list->type == '%')
		mem = 0;
	i = list->length - l - mem;
	if (i > 0)
		ft_write_alot(i, c);
	return (mem);
}
