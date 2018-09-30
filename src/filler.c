/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 23:41:09 by osavytsk          #+#    #+#             */
/*   Updated: 2018/07/27 23:41:09 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

extern t_config	*g_entity;

t_list	*get_moves(void)
{
	int		x;
	int		y;
	t_list	*cor_move;
	int		*ret;

	cor_move = NULL;
	x = 0;
	y = 0;
	while (g_entity->map[x])
	{
		while (x < g_entity->row && g_entity->map[x][y])
		{
			if ((ret = can_put(x, y)))
			{
				ft_lstadd(&cor_move, ft_lstnew((int[]) {ret[0], ret[1]}, 8));
				free(ret);
				ret = NULL;
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (cor_move);
}

void	make_move(t_list *cor_move)
{
	t_list	*top;
	int		best_x;
	int		best_y;
	int		*way;

	way = get_way(0, 0, 0, 0);
	best_x = ((int *)(cor_move->content))[0];
	best_y = ((int *)(cor_move->content))[1];
	top = cor_move;
	while (cor_move)
	{
		if (is_best(cor_move->content, best_x, best_y, way))
		{
			best_x = ((int *)cor_move->content)[0];
			best_y = ((int *)cor_move->content)[1];
		}
		cor_move = cor_move->next;
	}
	ft_printf("%d %d\n", best_x, best_y);
	free(top);
}

int		game_loop(void)
{
	t_list *cor_move;

	get_actual_map();
	cor_move = get_moves();
	if (!cor_move)
	{
		ft_printf("0 0\n");
		exit(1);
	}
	make_move(cor_move);
	free_map();
	return (1);
}

int		main(void)
{
	g_entity = malloc(sizeof(t_config));
	while (game_loop())
		continue;
	return (0);
}
