/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_actual_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 23:40:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/07/27 23:40:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

extern t_config	*g_entity;

char				*get_token(void)
{
	char *s;
	char *tmp;

	if (!get_next_line(STDIN_FILENO, &s))
		exit(0);
	tmp = s;
	if (*tmp != '$')
		return (tmp);
	while (*s && *s != 'p')
		s++;
	ME = *(s + 1) == '1' ? 'o' : 'x';
	OPP = *(s + 1) == '1' ? 'x' : 'o';
	free(tmp);
	tmp = NULL;
	return (tmp);
}

void				get_row_col(char *str)
{
	char *s;
	char *tmp;

	if (!str)
		get_next_line(STDIN_FILENO, &s);
	else
		s = str;
	tmp = s;
	while (!ft_isdigit(*s))
		s++;
	g_entity->row = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	g_entity->col = ft_atoi(s + 1);
	free(tmp);
}

void				get_map(void)
{
	char	*s;
	int		i;

	g_entity->map = malloc(sizeof(char *) * (g_entity->row + 1));
	i = 0;
	get_next_line(STDIN_FILENO, &s);
	free(s);
	while (i < g_entity->row)
	{
		get_next_line(STDIN_FILENO, &s);
		g_entity->map[i] = ft_strdup(s + 4);
		free(s);
		i++;
	}
	g_entity->map[i] = NULL;
}

void				get_current_token(void)
{
	char	*s;
	int		size;
	int		i;
	char	*tmp;

	i = 0;
	get_next_line(STDIN_FILENO, &s);
	tmp = s;
	while (*s && !ft_isdigit(*s))
		s++;
	if (*s == '0')
		size = 0;
	else
		size = ft_atoi(s);
	free(tmp);
	g_entity->token = malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		get_next_line(STDIN_FILENO, &s);
		g_entity->token[i] = ft_strdup(s);
		free(s);
		i++;
	}
	g_entity->token[i] = NULL;
}

void				get_actual_map(void)
{
	char	*s;

	s = get_token();
	get_row_col(s);
	get_map();
	get_current_token();
}
