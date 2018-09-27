/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 19:03:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 19:03:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (big == little)
		return ((char *)big);
	while (i != len && big[i] != '\0')
	{
		if (big[i] == little[j])
		{
			i++;
			j++;
		}
		else if (little[j] == '\0')
			return (char *)(&(*(big + i - j)));
		else
		{
			i = i + 1 - j;
			j = 0;
		}
		if (little[j] == '\0')
			return (char *)(&(*(big + i - j)));
	}
	return (0);
}
