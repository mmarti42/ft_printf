/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:44:31 by mmarti            #+#    #+#             */
/*   Updated: 2019/11/21 11:44:32 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int	ft_parse_float(va_list vaptr, t_format *list)
{
	long double a;

	if (list->mod.lb)
		a = va_arg(vaptr, long double);
	else
		a = va_arg(vaptr, double);
	return (dtoi(a, list));
}
