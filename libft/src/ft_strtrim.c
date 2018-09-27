/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 19:03:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 19:03:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isitspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	unsigned int	west;
	unsigned int	east;

	if (!s)
		return ("");
	east = ft_strlen(s) - 1;
	west = 0;
	while (isitspace(s[west]))
		west++;
	if (!s[west])
		return (ft_strnew(1));
	while (isitspace(s[east]))
		east--;
	east = (ft_strlen(s) - 1) - east;
	return (ft_strsub(s, west, (size_t)(ft_strlen(s) - (west + east))));
}
