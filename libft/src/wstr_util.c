/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:56:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:56:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		put_wchar(wchar_t c)
{
	if (c <= 0x7F)
		ft_putchar(c);
	else if (c <= 0x7FF)
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else
	{
		ft_putchar((c >> 18) + 0xF0);
		ft_putchar(((c >> 12) & 0x3F) + 0x80);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
}

int			wchar_len(wchar_t c)
{
	int		len;

	len = 0;
	if (c <= 0x7F)
		len = 1;
	else if (c <= 0x7FF)
		len = 2;
	else if (c <= 0xFFFF)
		len = 3;
	else
		len = 4;
	return (len);
}

void		put_nwstr(wchar_t *s, int n)
{
	int		i;

	i = 0;
	while (s[i] != '\0' & n > 0)
	{
		if (wchar_len(s[i]) > n)
			break ;
		n -= wchar_len(s[i]);
		put_wchar(s[i++]);
	}
}

int			wstr_nlen(wchar_t *s, int n)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[i] != '\0' && n > 0)
	{
		if (wchar_len(s[i]) > n)
			break ;
		n -= wchar_len(s[i]);
		len += wchar_len(s[i++]);
	}
	return (len);
}

int			wstr_len(wchar_t *s)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		len += wchar_len(s[i++]);
	return (len);
}
