/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:06:05 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/15 19:21:57 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		d_undefined_behavior(t_printf_format format)
{
	if (BYPASS_UNDEFINED_BEHAVIOR)
		return (0);
	if (format.flags.hashtag)
		return (1);
	return (0);
}

int				parser_d(t_printf_format format, va_list varlist)
{
	if (d_undefined_behavior(format))
		return (-1);
	else
	{
		if (format.type == 'D')
			return (print_d(&format, (long)va_arg(varlist, long)));
		if (!format.modifier)
			return (print_d(&format, (int)va_arg(varlist, int)));
		if (format.modifier == 1)
			return (print_d(&format, (char)va_arg(varlist, int)));
		if (format.modifier == 2)
			return (print_d(&format, (short)va_arg(varlist, int)));
		if (format.modifier == 3)
			return (print_d(&format, (long)va_arg(varlist, long)));
		if (format.modifier == 4)
			return (print_d(&format, (long long)va_arg(varlist, long long)));
		if (format.modifier == 5)
			return (print_d(&format, (intmax_t)va_arg(varlist, intmax_t)));
		if (format.modifier == 6)
			return (print_d(&format, (size_t)va_arg(varlist, size_t)));
		return (-1);
	}
}
