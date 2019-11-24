/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 23:03:58 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/15 23:03:59 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*c;
	size_t	size;
	int		i;

	if (!s || !f)
		return (0);
	size = ft_strlen(s) + 1;
	i = 0;
	c = (char *)ft_memalloc(size);
	if (!c)
		return (NULL);
	while (s[i] != '\0')
	{
		c[i] = f(s[i]);
		i++;
	}
	return (c);
}
