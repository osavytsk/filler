/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:47:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:47:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			low_c(va_list *arg, t_flags *flag)
{
	unsigned char	c;
	int				len;

	len = 1;
	if (flag->e_size == l)
		return (up_c(arg, flag));
	c = (unsigned char)va_arg(*arg, int);
	if (flag->width && !flag->minus && !flag->zero)
		put_space(flag->width, len);
	if (flag->width && flag->zero && !flag->minus)
		put_zero(flag->width, len);
	write(1, &c, 1);
	if (flag->width && flag->minus)
		put_space(flag->width, len);
	return (flag->width > len ? flag->width : len);
}
