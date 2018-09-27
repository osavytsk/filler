/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:47:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:47:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		low_p(va_list *arg, t_flags *flag)
{
	void		*ptr;
	uintmax_t	nb;
	int			len;

	ptr = va_arg(*arg, void*);
	nb = (unsigned long)ptr;
	len = take_ui_flag_len(nb, flag, 16);
	if (!flag->sharp)
		len += 2;
	put_uint_left_space(flag, len, nb, 4);
	if (!(flag->prec && !flag->precision && !nb))
		take_ui(nb, "0123456789abcdef", 16);
	if (flag->minus && flag->width)
		put_space(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
