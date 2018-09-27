/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:47:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:47:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		low_x(va_list *arg, t_flags *flag)
{
	uintmax_t		hex;
	int				len;

	hex = take_utype(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	len = take_ui_flag_len(hex, flag, 16);
	put_uint_left_space(flag, len, hex, 1);
	if (!(flag->prec && !flag->precision && !hex))
		take_ui(hex, "0123456789abcdef", 16);
	if (flag->width && flag->minus)
		put_space(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
