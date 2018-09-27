/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:47:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:47:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		low_s(va_list *arg, t_flags *flag)
{
	char	*str;
	int		len;
	int		isnull;

	isnull = 0;
	if (flag->e_size == l)
		return (up_s(arg, flag));
	str = va_arg(*arg, char *);
	len = (flag->precision) ? str_nlen(str, flag->precision) : ft_strlen(str);
	if (str == NULL)
	{
		isnull = 1;
		len = (flag->precision) ? str_nlen("(null)", flag->precision) : 6;
	}
	if (flag->prec && flag->precision == 0)
		len = 0;
	put_str_left_space(flag, len);
	if (!(flag->prec && !flag->precision) && !isnull)
		put_nstr(str, len);
	else if (isnull)
		put_nstr("(null)", len);
	if (flag->minus && flag->width)
		put_space(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
