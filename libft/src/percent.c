/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:51:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:51:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		percent(va_list *arg, t_flags *flag)
{
	int		len;

	(void)arg;
	len = 1;
	if (flag->width && !flag->zero && !flag->minus)
		put_space(flag->width, len);
	if (flag->width && flag->zero && !flag->minus)
		put_zero(flag->width, len);
	ft_putchar('%');
	if (flag->width && flag->minus)
		put_space(flag->width, len);
	return (flag->width > len ? flag->width : len);
}
