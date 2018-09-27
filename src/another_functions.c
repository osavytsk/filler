/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 23:46:40 by osavytsk          #+#    #+#             */
/*   Updated: 2018/07/27 23:46:40 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

extern t_config	*g_entity;

void	free_2d(char ***ar_src)
{
	char	**ar;
	int		i;

	ar = *ar_src;
	i = 0;
	while (ar[i])
	{
		free(ar[i]);
		i++;
	}
	free(ar);
	*ar_src = NULL;
}

void	free_map(void)
{
	free_2d(&(g_entity->map));
	free_2d(&(g_entity->token));
}

int		abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int		is_best(int *src, int init_x, int init_y, const int *way)
{
	int was;
	int now;
	int way_x;
	int way_y;

	way_x = way[0];
	way_y = way[1];
	now = abs(way_x - src[0]) + abs(way_y - src[1]);
	was = abs(way_x - init_x) + abs(way_y - init_y);
	if (now < was)
		return (1);
	return (0);
}
