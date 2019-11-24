/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:45:18 by mmarti            #+#    #+#             */
/*   Updated: 2019/11/21 15:45:19 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int		ft_write_char(void *data, t_format *list)
{
	int	len_prev;
	int	len_post;
	int i;

	i = 0;
	len_prev = ft_strlen(list->prev);
	len_post = ft_strlen(list->post);
	write(1, list->prev, len_prev);
	if (list->length > 1 && list->fl.minus == 0)
	{
		if (list->fl.null == 1)
			i = ft_write_alot(list->length - 1, '0');
		else
			i = ft_write_alot(list->length - 1, ' ');
	}
	if ((list->mod.l) == 1)
		write(1, (wchar_t*)data, 1);
	else
		write(1, (unsigned char*)data, 1);
	if (list->length > 1 && list->fl.minus == 1)
		i = ft_write_alot(list->length - 1, ' ');
	write(1, list->post, len_post);
	return (len_prev + 1 + len_post + i);
}
