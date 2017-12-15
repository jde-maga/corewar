/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:53:17 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 16:38:37 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	calibrate_format_c(t_printf_format *format)
{
	format->pad_size--;
	if (format->pad_size < 0)
		format->pad_size = 0;
	format->flags.plus = 0;
	format->flags.space = 0;
}

int		print_c(t_printf_format format, unsigned char c)
{
	char *e;

	calibrate_format_c(&format);
	e = ft_strnew(format.pad_size + 1);
	if (format.flags.minus)
		e[0] = c;
	get_pad(format.pad_size, format.flags.zero, &e);
	if (!format.flags.minus)
		e[format.pad_size] = c;
	write(1, e, format.pad_size + 1);
	free(e);
	return (format.pad_size + 1);
}
