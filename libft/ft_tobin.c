/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 07:13:26 by mmarti            #+#    #+#             */
/*   Updated: 2019/05/16 16:04:31 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tobin(int num)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = (char *)ft_memalloc(ft_maxlog2(num) + 1)))
		return (0);
	while (num != 0)
	{
		res[i++] = num % 2 + 48;
		num /= 2;
	}
	return (ft_strrev(res));
}
