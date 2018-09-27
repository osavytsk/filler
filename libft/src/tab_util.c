/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:51:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:51:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_space(int width, int len)
{
	int	n;

	n = width - len;
	while (n-- > 0)
		ft_putchar(' ');
}

void	put_zero(int width, int len)
{
	int	n;

	n = width - len;
	while (n-- > 0)
		ft_putchar('0');
}
