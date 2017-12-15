/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:36:17 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 15:07:28 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	calibrate_format_d(t_printf_format *format, long d)
{
	if (format->precision_size == 0 && d == 0)
		format->hide_print = 1;
	if (d < 0 && (format->flags.zero || format->precision_size > 0))
		format->precision_size++;
	format->precision_size -= ft_size_long(d);
	if (format->precision_size < 0)
		format->precision_size = 0;
	format->pad_size -= ft_size_long(d);
	format->pad_size -= format->precision_size;
	if (d >= 0)
		format->pad_size -= (format->flags.plus + format->flags.space
								- format->hide_print);
	if (format->pad_size < 0)
		format->pad_size = 0;
}

int		get_d_size(t_printf_format *format, long d)
{
	int i;

	i = 0;
	i += format->pad_size;
	i += format->precision_size;
	i += ft_size_long(d);
	if (d >= 0)
		i += format->flags.plus;
	if (d >= 0)
		i += format->flags.space;
	i -= format->hide_print;
	return (i);
}

void	display_d_no_minus_flag(t_printf_format *format, long d)
{
	char *e;
	char *bufd;

	e = ft_strnew(get_d_size(format, d));
	if (format->flags.zero)
		get_flags(format, ft_ispos(d), &e);
	get_pad(format->pad_size, format->flags.zero, &e);
	if (!format->flags.zero)
		get_flags(format, ft_ispos(d), &e);
	if (d < 0 && format->precision_size)
		ft_strcat(e, "-");
	get_precision(format->precision_size, &e);
	if (!format->hide_print)
	{
		if (d < 0 && (format->precision_size || format->flags.zero))
			bufd = ft_itoa_long(-d);
		else
			bufd = ft_itoa_long(d);
		ft_strcat(e, bufd);
		free(bufd);
	}
	ft_putstr(e);
	free(e);
}

void	display_d_minus_flag(t_printf_format *format, long d)
{
	char *e;
	char *bufd;

	e = ft_strnew(get_d_size(format, d));
	get_flags(format, ft_ispos(d), &e);
	if (d < 0 && (format->precision_size || format->flags.zero))
		ft_strcat(e, "-");
	get_precision(format->precision_size, &e);
	if (!format->hide_print)
	{
		if (d < 0 && (format->precision_size || format->flags.zero))
			bufd = ft_itoa_long(-d);
		else
			bufd = ft_itoa_long(d);
		ft_strcat(e, bufd);
		free(bufd);
	}
	get_pad(format->pad_size, format->flags.zero, &e);
	ft_putstr(e);
	free(e);
}

int		print_d(t_printf_format *format, long d)
{
	calibrate_format_d(format, d);
	if (!format->flags.minus)
		display_d_no_minus_flag(format, d);
	else if (format->flags.minus)
		display_d_minus_flag(format, d);
	return (get_d_size(format, d));
}
