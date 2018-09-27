/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:51:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:51:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_nstr(char *str, int n)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (n-- > 0 && str[i] != '\0')
		ft_putchar(str[i++]);
}

int		str_nlen(char *str, int n)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while ((n-- > 0) && (str[i] != '\0'))
		i++;
	return (i);
}

void	put_str_left_space(t_flags *flag, int len)
{
	if (flag->width && !flag->minus && !flag->zero)
		put_space(flag->width, len);
	if (flag->width && flag->zero && !flag->minus)
		put_zero(flag->width, len);
}
