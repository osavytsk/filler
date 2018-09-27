/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 23:43:24 by osavytsk          #+#    #+#             */
/*   Updated: 2018/07/27 23:43:24 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

extern t_config	*g_entity;

int					if_filled(int x, int y, int *filled)
{
	if (x < 0 || y < 0
		|| x >= g_entity->row || y >= g_entity->col)
		return (0);
	if (g_entity->map[x][y] == OPP - 32
		|| g_entity->map[x][y] == OPP)
		return (0);
	if (*filled && (g_entity->map[x][y] == ME - 32
		|| g_entity->map[x][y] == ME))
		return (0);
	else if (g_entity->map[x][y] == ME
			|| g_entity->map[x][y] == ME - 32)
		*filled = 1;
	return (1);
}

int					can_fill_cur(int x, int y, int corner_x, int corner_y)
{
	char	**token;
	int		filled;
	int		i;
	int		j;

	i = 0;
	j = 0;
	filled = 0;
	token = g_entity->token;
	while (token[i])
	{
		while (token[i][j])
		{
			if (token[i][j] == '*')
				if (!if_filled(x - corner_x + i, y - corner_y + j, &filled))
					return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if (filled == 0)
		return (0);
	return (1);
}

int					*can_put(int i, int j)
{
	int x;
	int y;
	int *ret;

	x = 0;
	y = 0;
	ret = malloc(8);
	while (g_entity->token[x])
	{
		while (g_entity->token[x][y])
		{
			if (g_entity->token[x][y] == '*')
				if (can_fill_cur(i, j, x, y))
				{
					ret[0] = i - x;
					ret[1] = j - y;
					return (ret);
				}
			y++;
		}
		y = 0;
		x++;
	}
	return (NULL);
}
