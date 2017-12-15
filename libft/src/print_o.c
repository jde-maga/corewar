/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:49:30 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:33:19 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	calibrate_format_o(t_printf_format *format, char *octal,
							unsigned long o)
{
	if (format->precision_size == 0 && o == 0)
		format->hide_print = 1;
	if (!format->hide_print)
	{
		if (format->precision_size > (int)ft_strlen(octal))
			format->flags.hashtag = 0;
		if (o == 0)
		{
			format->flags.zero = 0;
			format->flags.hashtag = 0;
		}
		format->precision_size -= ft_strlen(octal);
		if (format->precision_size < 0)
			format->precision_size = 0;
		format->pad_size -= (format->precision_size + ft_strlen(octal));
		if (format->flags.hashtag)
			format->pad_size--;
		if (format->pad_size < 0)
			format->pad_size = 0;
	}
	format->flags.space = 0;
	format->flags.plus = 0;
}

static char	*get_octal(unsigned long o)
{
	char	*otp;
	int		i;

	otp = ft_strnew(64);
	i = 0;
	while (o >= 8)
	{
		otp[i] = (o % 8) + 48;
		o /= 8;
		i++;
	}
	otp[i] = (o % 8) + 48;
	otp[i + 1] = '\0';
	ft_strrev(otp);
	return (otp);
}

static int	print_o_minus_flag(t_printf_format format, char *octal)
{
	char *e;

	e = ft_strnew(format.pad_size + (format.hide_print ? 0 :
		(format.precision_size + ft_strlen(octal))) + format.flags.hashtag);
	get_flags(&format, 1, &e);
	if (!format.hide_print)
	{
		get_precision(format.precision_size, &e);
		ft_strcat(e, octal);
	}
	get_pad(format.pad_size, format.flags.zero, &e);
	ft_putstr(e);
	free(e);
	return (ft_strlen(e));
}

static int	print_o_no_minus_flag(t_printf_format format, char *octal)
{
	char *e;

	e = ft_strnew(format.pad_size + (format.hide_print ? 0 :
		(format.precision_size + ft_strlen(octal))) + format.flags.hashtag);
	get_pad(format.pad_size, format.flags.zero, &e);
	get_flags(&format, 1, &e);
	if (!format.hide_print)
	{
		get_precision(format.precision_size, &e);
		ft_strcat(e, octal);
	}
	ft_putstr(e);
	free(e);
	return (ft_strlen(e));
}

int			print_o(t_printf_format format, unsigned long o)
{
	char	*octal;
	int		ret;

	octal = get_octal(o);
	calibrate_format_o(&format, octal, o);
	if (format.flags.minus)
		ret = print_o_minus_flag(format, octal);
	else
		ret = print_o_no_minus_flag(format, octal);
	free(octal);
	return (ret);
}
