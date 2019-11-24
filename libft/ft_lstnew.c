/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 05:48:02 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/16 05:48:04 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (0);
	if (!content)
	{
		tmp->content_size = 0;
		tmp->content = 0;
		tmp->next = 0;
		return (tmp);
	}
	if (!(tmp->content = (void *)malloc(content_size)))
		return (0);
	ft_memcpy(tmp->content, content, content_size);
	tmp->content_size = content_size;
	tmp->next = 0;
	return (tmp);
}
