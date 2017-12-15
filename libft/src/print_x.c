/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:54:14 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:42:56 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	calibrate_format_x(t_printf_format *format, char *hexa,
				unsigned long x)
{
	if (format->flags.hashtag)
		format->flags.hashtag++;
	if (format->precision_size == 0 && x == 0)
		format->hide_print = 1;
	if (!format->hide_print)
	{
		format->precision_size -= ft_strlen(hexa);
		if (format->precision_size < 0)
			format->precision_size = 0;
		format->pad_size -= (format->precision_size + ft_strlen(hexa));
		if (x)
		{
			if (format->flags.hashtag)
				format->pad_size -= 2;
		}
		else
			format->flags.hashtag = 0;
		if (format->pad_size < 0)
			format->pad_size = 0;
	}
	format->flags.plus = 0;
	format->flags.space = 0;
}

char		*get_hexa_x(unsigned long x, char type)
{
	char	*otp;
	int		i;

	otp = ft_strnew(21);
	i = 0;
	while (x > 15)
	{
		otp[i] = ft_printf_hexa_table(x % 16, type);
		x /= 16;
		i++;
	}
	otp[i] = ft_printf_hexa_table(x % 16, type);
	otp[i + 1] = '\0';
	ft_strrev(otp);
	return (otp);
}

static int	display_x_no_minus_flag(t_printf_format format, char *hexa)
{
	char *e;

	e = ft_strnew(format.pad_size + (format.hide_print ? 0 :
			(format.precision_size + ft_strlen(hexa)) + format.flags.hashtag));
	if (!format.hide_print)
	{
		if (format.flags.zero)
			get_flags(&format, 1, &e);
		get_pad(format.pad_size, format.flags.zero, &e);
		if (!format.flags.zero)
			get_flags(&format, 1, &e);
		get_precision(format.precision_size, &e);
		ft_strcat(e, hexa);
	}
	else
		get_pad(format.pad_size, format.flags.zero, &e);
	ft_putstr(e);
	free(e);
	return (ft_strlen(e));
}

static int	display_x_minus_flag(t_printf_format format, char *hexa)
{
	char *e;

	e = ft_strnew(format.pad_size + (format.hide_print ? 0 :
			(format.precision_size + ft_strlen(hexa)) + format.flags.hashtag));
	if (!format.hide_print)
	{
		get_flags(&format, 1, &e);
		get_precision(format.precision_size, &e);
		ft_strcat(e, hexa);
	}
	get_pad(format.pad_size, format.flags.zero, &e);
	ft_putstr(e);
	free(e);
	return (ft_strlen(e));
}

int			print_x(t_printf_format format, unsigned long x)
{
	char	*hexa;
	int		ret;

	hexa = get_hexa_x(x, format.type);
	calibrate_format_x(&format, hexa, x);
	if (format.flags.minus)
		ret = display_x_minus_flag(format, hexa);
	else
		ret = display_x_no_minus_flag(format, hexa);
	free(hexa);
	return (format.pad_size + (format.hide_print ? 0 : (format.precision_size +
				ft_strlen(hexa)) + format.flags.hashtag));
}
