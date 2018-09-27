/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 19:03:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 19:03:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_first(char c)
{
	if (c == ' ' || c == '\f' || c == '\r')
	{
		return (1);
	}
	else if (c == '\n' || c == '\v' || c == '\t')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int			ft_atoi(const char *str)
{
	int pos;
	int i;
	int sign;

	i = 0;
	sign = 1;
	pos = 0;
	while (ft_check_first(str[pos]) == 1)
	{
		pos++;
	}
	if (str[pos] == '-')
	{
		sign = -1;
	}
	if (str[pos] == '-' || str[pos] == '+')
	{
		pos++;
	}
	while (str[pos] <= '9' && str[pos] >= '0')
	{
		i = i * 10 + str[pos] - 48;
		pos++;
	}
	return (i * sign);
}
