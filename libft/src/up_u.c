/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:56:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:56:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		up_u(va_list *arg, t_flags *flag)
{
	unsigned long int	nb;
	int					len;

	nb = va_arg(*arg, unsigned long int);
	if (flag->prec)
		flag->zero = 0;
	len = take_ui_flag_len(nb, flag, 10);
	put_uint_left_space(flag, len, nb, 0);
	if (!(flag->prec && !flag->precision && !nb))
		take_ui(nb, "0123456789", 10);
	if (flag->width && flag->minus)
		put_space(flag->width, len);
	return ((flag->width) ? flag->width : len);
}
