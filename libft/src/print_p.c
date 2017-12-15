/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 19:14:12 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:34:38 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	calibrate_format_p(t_printf_format *format, char *hexa,
								unsigned long p)
{
	if (!p && format->precision_size == 0)
		format->hide_print = 1;
	format->precision_size -= ft_strlen(hexa);
	if (format->precision_size < 0)
		format->precision_size = 0;
	format->pad_size -= (format->precision_size + ft_strlen(hexa) + 2);
	if (format->pad_size < 0)
		format->pad_size = 0;
	format->flags.hashtag = 1;
	format->flags.plus = 0;
	format->flags.space = 0;
}

static char	*get_ptr_p(unsigned long p)
{
	char	*otp;
	int		i;

	otp = ft_strnew(21);
	i = 0;
	while (p > 15)
	{
		otp[i] = ft_printf_hexa_table(p % 16, 'x');
		p /= 16;
		i++;
	}
	otp[i] = ft_printf_hexa_table(p % 16, 'x');
	otp[i + 1] = '\0';
	ft_strrev(otp);
	return (otp);
}

static int	display_p_no_minus_flag(t_printf_format format, char *ptr)
{
	char *e;

	e = ft_strnew(format.pad_size + ft_strlen(ptr) +
			format.precision_size + 2 - format.hide_print);
	if (format.flags.zero)
		get_flags(&format, 1, &e);
	get_pad(format.pad_size, format.flags.zero, &e);
	if (!format.flags.zero)
		get_flags(&format, 1, &e);
	get_precision(format.precision_size, &e);
	if (!format.hide_print)
		ft_strcat(e, ptr);
	ft_putstr(e);
	free(e);
	return (ft_strlen(e));
}

static int	display_p_minus_flag(t_printf_format format, char *ptr)
{
	char *e;

	e = ft_strnew(format.pad_size + ft_strlen(ptr) +
			format.precision_size + 2 - format.hide_print);
	get_flags(&format, 1, &e);
	get_precision(format.precision_size, &e);
	if (!format.hide_print)
		ft_strcat(e, ptr);
	get_pad(format.pad_size, format.flags.zero, &e);
	ft_putstr(e);
	free(e);
	return (ft_strlen(e));
}

int			print_p(t_printf_format format, void *p)
{
	char	*ptr;
	int		ret;

	ptr = get_ptr_p((unsigned long)p);
	calibrate_format_p(&format, ptr, (unsigned long)p);
	if (format.flags.minus)
		ret = display_p_minus_flag(format, ptr);
	else
		ret = display_p_no_minus_flag(format, ptr);
	free(ptr);
	return (ret);
}
