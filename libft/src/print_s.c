/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:56:59 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:43:20 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		calibrate_format_s(t_printf_format *format, const char *s)
{
	if (format->precision_size == -1 ||
		format->precision_size > (int)ft_strlen(s))
		format->precision_size = ft_strlen(s);
	format->pad_size -= format->precision_size;
	if (format->pad_size < 0)
		format->pad_size = 0;
}

static char		*null_string(void)
{
	char *str;

	str = ft_strnew(6);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	return (str);
}

int				print_s(t_printf_format format, char *s)
{
	char *e;
	char *bufnull;

	bufnull = NULL;
	if (s == NULL)
	{
		s = null_string();
		bufnull = s;
	}
	calibrate_format_s(&format, s);
	e = ft_strnew(format.precision_size + format.pad_size);
	if (!format.flags.minus)
		get_pad(format.pad_size, format.flags.zero, &e);
	ft_strncat(e, s, format.precision_size);
	if (format.flags.minus)
		get_pad(format.pad_size, format.flags.zero, &e);
	ft_putstr(e);
	free(e);
	if (bufnull)
		free(bufnull);
	return (format.precision_size + format.pad_size);
}
