/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:56:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:56:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		up_s(va_list *arg, t_flags *flag)
{
	wchar_t		*str;
	int			len;
	int			null;

	null = 0;
	str = va_arg(*arg, wchar_t*);
	len = (flag->precision) ? wstr_nlen(str, flag->precision) : wstr_len(str);
	if (str == NULL)
	{
		null = 1;
		len = (flag->precision) ? str_nlen("(null)", flag->precision) : 6;
	}
	if (flag->prec && flag->precision == 0)
		len = 0;
	if (flag->width && !flag->minus && !flag->zero)
		put_space(flag->width, len);
	if (flag->width && flag->zero && !flag->minus)
		put_zero(flag->width, len);
	if (!(flag->prec && flag->precision == 0) && null == 0)
		put_nwstr(str, len);
	else if (null == 1)
		put_nstr("(null)", len);
	if (flag->minus && flag->width)
		put_space(flag->width, len);
	return ((flag->width) > len ? flag->width : len);
}
