/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:11:24 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 14:26:56 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		c_undefined_behavior(t_printf_format format)
{
	if (BYPASS_UNDEFINED_BEHAVIOR)
		return (0);
	if (format.flags.zero == 1 || format.flags.plus || format.flags.space ||
		format.flags.hashtag == 1)
		return (1);
	if (format.precision_size > 0)
		return (1);
	if (format.modifier && format.modifier != 3)
		return (1);
	return (0);
}

int				parser_c(t_printf_format format, va_list varlist)
{
	if (c_undefined_behavior(format) && format.type != '%')
		return (-1);
	else
	{
		if (format.type == 'C')
			return (print_lc(&format, (wint_t)va_arg(varlist, wint_t)));
		if (format.type == '%')
			return (print_c(format, '%'));
		if (!format.modifier)
			return (print_c(format, (unsigned char)va_arg(varlist, int)));
		if (format.modifier == 3)
			return (print_lc(&format, (wint_t)va_arg(varlist, wint_t)));
	}
	return (-1);
}
