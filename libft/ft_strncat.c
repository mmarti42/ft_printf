/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:13:02 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/09 17:13:06 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	char *string;

	string = str1;
	while (*string != '\0')
		string++;
	while (*str2 != '\0' && n--)
		*string++ = *str2++;
	*string = '\0';
	return (str1);
}
