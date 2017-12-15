/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:50:52 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:40:47 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		calibrate_format_u(t_printf_format *format, unsigned long u)
{
	if (format->precision_size == 0 && u == 0)
		format->hide_print = 1;
	if (!format->hide_print)
	{
		format->precision_size -= ft_size_ulong(u);
		if (format->precision_size < 0)
			format->precision_size = 0;
		format->pad_size -= (format->precision_size + ft_size_ulong(u));
		if (format->pad_size < 0)
			format->pad_size = 0;
	}
}

static int	display_u_minus_flag(t_printf_format format, unsigned long u)
{
	char *e;
	char *bufu;

	e = ft_strnew(format.pad_size + (format.hide_print ? 0 :
				(format.precision_size + ft_size_ulong(u))));
	get_precision(format.precision_size, &e);
	if (!format.hide_print)
	{
		bufu = ft_itoa_ulong(u);
		ft_strcat(e, bufu);
		free(bufu);
	}
	get_pad(format.pad_size, format.flags.zero, &e);
	ft_putstr(e);
	free(e);
	return (ft_strlen(e));
}

static int	display_u_no_minus_flag(t_printf_format format, unsigned long u)
{
	char *e;
	char *bufu;

	e = ft_strnew(format.pad_size + (format.hide_print ? 0 :
				(format.precision_size + ft_size_ulong(u))));
	get_pad(format.pad_size, format.flags.zero, &e);
	get_precision(format.precision_size, &e);
	if (!format.hide_print)
	{
		bufu = ft_itoa_ulong(u);
		ft_strcat(e, bufu);
		free(bufu);
	}
	ft_putstr(e);
	free(e);
	return (ft_strlen(e));
}

int			print_u(t_printf_format format, unsigned long u)
{
	int		ret;

	calibrate_format_u(&format, u);
	if (format.flags.minus)
		ret = display_u_minus_flag(format, u);
	else
		ret = display_u_no_minus_flag(format, u);
	return (ret);
}
