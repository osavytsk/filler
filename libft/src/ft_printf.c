/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:31:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:31:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	null_flags_struct(t_flags *flag)
{
	flag->precision = 0;
	flag->prec = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->sharp = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->e_size = 0;
}

int		take_specifier(char **format, t_flags *flag, va_list *arg)
{
	static int	(*f[])(va_list*, t_flags*) = {low_s, up_s,
			low_p, low_d, up_d, low_i, low_o, up_o,
			low_u, up_u, low_x, up_x, low_c, up_c,
			percent, 0};
	static char	specs[] = {'s', 'S', 'p', 'd', 'D', 'i', 'o', 'O', 'u', 'U',
	'x', 'X', 'c', 'C', '%', 0};
	int			i;
	int			ret;

	i = 0;
	while (specs[i] != **format && specs[i])
		i++;
	if (**format != '\0' && specs[i] == **format)
	{
		ret = f[i](arg, flag);
		(*format)++;
		return (ret);
	}
	if (**format != '\0')
	{
		(*format)++;
		return (undef(*(*format - 1), flag));
	}
	return (0);
}

int		pars(char **format, t_flags *flag, va_list *arg)
{
	int		ret;

	ret = 0;
	while (**format)
	{
		if (**format == '%')
		{
			null_flags_struct(flag);
			(*format)++;
			take_options(format, flag, arg);
			ret += take_specifier(format, flag, arg);
		}
		else if (**format != '\0')
		{
			ft_putchar(**format);
			(*format)++;
			ret++;
		}
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	t_flags		*flag;
	int			ret;

	ret = 0;
	flag = ft_memalloc(sizeof(t_flags));
	va_start(arg, format);
	ret = pars((char **) &format, flag, &arg);
	va_end(arg);
	ft_memdel((void**)&flag);
	return (ret);
}
