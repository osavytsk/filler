/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 23:46:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/09/27 23:46:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
#include "../libft/includes/libft.h"
# define ME	 	g_entity->player
# define OPP	g_entity->opp

typedef struct		s_config
{
	char			**map;
	char			player;
	char			opp;
	int				row;
	int				col;
	char			**token;
}					t_config;

t_config			*g_entity;

void				get_actual_map();
int					*can_put(int i, int j);
int					*get_way(int x, int y, int medium_x, int medium_y);
int					is_best(int *src, int init_x, int init_y, const int *way);
void				free_2d(char ***ar_src);
void				free_map(void);
int					abs(int a);

#endif
