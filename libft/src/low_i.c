/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:47:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:47:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		low_i(va_list *arg, t_flags *flag)
{
	intmax_t		nb;
	int				len;

	nb = take_type(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	len = take_flag_len(nb, flag);
	put_int_left_space(flag, len, nb);
	if (!(flag->prec && flag->precision == 0 && nb == 0))
		take_int(nb);
	if (flag->minus && flag->width)
		put_space(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
