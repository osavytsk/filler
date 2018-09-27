/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:56:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:56:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		up_o(va_list *arg, t_flags *flag)
{
	unsigned long int	nb;
	int					len;

	nb = va_arg(*arg, unsigned long int);
	if (flag->prec)
		flag->zero = 0;
	len = take_ui_flag_len(nb, flag, 8);
	if (flag->sharp && flag->precision > 0)
	{
		flag->precision--;
		len--;
	}
	put_uint_left_space(flag, len, nb, 3);
	if (!(flag->prec && !flag->precision && !nb) &&
			!(flag->sharp && !nb))
        take_ui(nb, "012345678", 8);
	if (flag->width && flag->minus)
		put_space(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
