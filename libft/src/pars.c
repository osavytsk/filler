/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:51:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:51:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		take_options(char **str, t_flags *flag, va_list *arg)
{
	if (**str != '0' && ft_isdigit(**str))
		take_width(str, flag, arg);
	if (**str == '.')
		take_precision(str, flag, arg);
	if (**str == 'h' || **str == 'l' || **str == 'j' || **str == 'z')
		take_length(str, flag, arg);
	if (**str == '#' || **str == '0' || **str == '-' || **str == '+'
			|| **str == ' ')
		take_flag(str, flag, arg);
}

void		take_flag(char **str, t_flags *flag, va_list *arg)
{
	while (**str == '#' || **str == '0' || **str == '-' || **str == '+'
			|| **str == ' ')
	{
		if (**str == '#')
			flag->sharp = 1;
		if (**str == '0')
			flag->zero = 1;
		if (**str == '-')
			flag->minus = 1;
		if (**str == '+')
			flag->plus = 1;
		if (**str == ' ')
			flag->space = 1;
		(*str)++;
	}
	take_options(str, flag, arg);
}

void		take_width(char **str, t_flags *flag, va_list *arg)
{
	flag->width = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
	take_options(str, flag, arg);
}

void		take_precision(char **str, t_flags *flag, va_list *arg)
{
	while (**str == '.')
	{
		flag->prec = 1;
		(*str)++;
		flag->precision = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	take_options(str, flag, arg);
}

void		take_length(char **str, t_flags *flag, va_list *arg)
{
	if (**str == 'h')
	{
		if (*(*str + 1) == 'h' && flag->e_size < 3)
			flag->e_size = hh;
		else if (flag->e_size < 2)
			flag->e_size = h;
	}
	if (**str == 'l')
	{
		if (*(*str + 1) == 'l' && flag->e_size < 5)
			flag->e_size = ll;
		else if (flag->e_size < 4)
			flag->e_size = l;
	}
	if (**str == 'j' && flag->e_size < 6)
		flag->e_size = j;
	if (**str == 'z')
		flag->e_size = z;
	if (flag->e_size)
		(*str)++;
	if (flag->e_size == hh || flag->e_size == ll)
		(*str)++;
	take_options(str, flag, arg);
}
