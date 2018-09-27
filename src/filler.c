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
	t_list	*correct_moves;
	int		*ret;

	correct_moves = NULL;
	x = 0;
	y = 0;
	while (g_entity->map[x])
	{
		while (x < g_entity->row && g_entity->map[x][y])
		{
			if ((ret = can_put(x, y)))
			{
				ft_lstadd(&correct_moves, ft_lstnew((int[]) {ret[0], ret[1]}, 8));
				free(ret);
				ret = NULL;
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (correct_moves);
}

void	make_move(t_list *correct_moves)
{
	t_list	*top;
	int		best_x;
	int		best_y;
	int		*way;

	way = get_way(0, 0, 0, 0);
	best_x = ((int *)(correct_moves->content))[0];
	best_y = ((int *)(correct_moves->content))[1];
	top = correct_moves;
	while (correct_moves)
	{
		if (is_best(correct_moves->content, best_x, best_y, way))
		{
			best_x = ((int *)correct_moves->content)[0];
			best_y = ((int *)correct_moves->content)[1];
		}
		correct_moves = correct_moves->next;
	}
	ft_printf("%d %d\n", best_x, best_y);
	free(top);
}

int		game_loop(void)
{
	t_list *correct_moves;

	get_actual_map();
	correct_moves = get_moves();
	if (!correct_moves)
	{
		ft_printf("0 0\n");
		exit(1);
	}
	make_move(correct_moves);
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
