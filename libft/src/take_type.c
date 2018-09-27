/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:34:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:34:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t		take_utype(va_list *arg, t_flags *flag)
{
	uintmax_t		argument;

	argument = va_arg(*arg, uintmax_t);
	if (flag->e_size == hh)
		return (unsigned char)argument;
	if (flag->e_size == h)
		return (unsigned short)argument;
	if (flag->e_size == l)
		return (unsigned long)argument;
	if (flag->e_size == ll)
		return (unsigned long long)argument;
	if (flag->e_size == j)
		return (argument);
	if (flag->e_size == z)
		return (size_t)argument;
	return (unsigned int)argument;
}

intmax_t		take_type(va_list *arg, t_flags *flag)
{
	intmax_t		argument;

	argument = va_arg(*arg, intmax_t);
	if (flag->e_size == hh)
		return (signed char)argument;
	if (flag->e_size == h)
		return (short)argument;
	if (flag->e_size == l)
		return (long)argument;
	if (flag->e_size == ll)
		return (long long)argument;
	if (flag->e_size == j)
		return (argument);
	if (flag->e_size == z)
		return (size_t)argument;
	return (int)argument;
}
