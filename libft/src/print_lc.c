/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 18:22:43 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:55:13 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	calibrate_format_lc(t_printf_format *format, wint_t lc)
{
	format->pad_size -= utf_byte_size(lc);
	if (format->pad_size < 0)
		format->pad_size = 0;
	format->flags.plus = 0;
	format->flags.space = 0;
}

int		print_lc(t_printf_format *format, wint_t lc)
{
	char			*bufpad;
	unsigned char	*e;

	calibrate_format_lc(format, lc);
	e = ft_strnew_uchar(format->pad_size + utf_byte_size(lc));
	if (format->flags.minus)
	{
		get_utf_char((unsigned int)lc, &e);
		write(1, e, utf_byte_size(lc));
	}
	bufpad = ft_strnew(format->pad_size);
	get_pad(format->pad_size, format->flags.zero, &bufpad);
	write(1, bufpad, format->pad_size);
	free(bufpad);
	if (!format->flags.minus)
	{
		get_utf_char((unsigned int)lc, &e);
		write(1, e, utf_byte_size(lc));
	}
	free(e);
	return (format->pad_size + utf_byte_size(lc));
}
