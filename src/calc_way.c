/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 23:45:33 by osavytsk          #+#    #+#             */
/*   Updated: 2018/07/27 23:45:33 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

extern t_config	*g_entity;

static int			*get_next_dir(int i, int j, int x, int y)
{
	int way_x;
	int way_y;
	int *ret;

	way_x = 0;
	way_y = 0;
	while (g_entity->map[x])
	{
		while (x < g_entity->row && g_entity->map[x][y])
		{
			if (g_entity->map[x][y] == '.')
				if (!is_best((int[]) {x, y}, way_x, way_y, (int[]) {i, j}))
				{
					way_x = x;
					way_y = y;
				}
			y++;
		}
		y = 0;
		x++;
	}
	ret = malloc(8);
	ret[0] = way_x;
	ret[1] = way_y;
	return (ret);
}

int					*get_way(int x, int y, int medium_x, int medium_y)
{
	int i;

	i = 0;
	while (x < g_entity->row && g_entity->map[x])
	{
		while (g_entity->map[x][y])
		{
			if (g_entity->map[x][y] == ME ||
				g_entity->map[x][y] == ME - 32)
			{
				medium_x += x;
				medium_y += y;
				i++;
			}
			y++;
		}
		y = 0;
		x++;
	}
	medium_x = medium_x / i;
	medium_y = medium_y / i;
	return (get_next_dir(medium_x, medium_y, 0, 0));
}
