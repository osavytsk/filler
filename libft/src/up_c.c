/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:56:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:56:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		up_c(va_list *arg, t_flags *flag)
{
	wchar_t			c;
	int				len;

	c = (wchar_t)va_arg(*arg, wint_t);
	len = wchar_len(c);
	if (flag->width && !flag->minus && !flag->zero)
		put_space(flag->width, len);
	if (flag->width && flag->zero && !flag->minus)
		put_zero(flag->width, len);
	put_wchar(c);
	if (flag->width && flag->minus)
		put_space(flag->width, len);
	return (flag->width > len ? flag->width : len);
}
