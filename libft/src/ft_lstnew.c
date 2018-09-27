/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 19:03:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 19:03:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new_elem;
	void		*l_content;

	if (!(new_elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		l_content = NULL;
		content_size = 0;
	}
	else
	{
		if (!(l_content = malloc(content_size)))
		{
			free(new_elem);
			return (NULL);
		}
		ft_memcpy(l_content, content, content_size);
	}
	new_elem->content = (void *)l_content;
	new_elem->content_size = content_size;
	new_elem->next = NULL;
	return (new_elem);
}
