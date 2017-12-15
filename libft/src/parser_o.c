/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:06:05 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/04 15:38:29 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		undefined_behavior_o(t_printf_format format)
{
	if (BYPASS_UNDEFINED_BEHAVIOR)
		return (0);
	if (format.flags.plus)
		return (1);
	if (format.flags.space)
		return (1);
	return (0);
}

int		parser_o(t_printf_format format, va_list varlist)
{
	if (undefined_behavior_o(format))
		return (-1);
	else
	{
		if (format.type == 'O')
			return (print_o(format, va_arg(varlist, unsigned long)));
		if (!format.modifier)
			return (print_o(format, va_arg(varlist, unsigned int)));
		if (format.modifier == 1)
			return (print_o(format, (unsigned char)va_arg(varlist, int)));
		if (format.modifier == 2)
			return (print_o(format, (unsigned short)va_arg(varlist, int)));
		if (format.modifier == 3)
			return (print_o(format, va_arg(varlist, unsigned long)));
		if (format.modifier == 4)
			return (print_o(format, va_arg(varlist, unsigned long long)));
		if (format.modifier == 5)
			return (print_o(format, va_arg(varlist, uintmax_t)));
		if (format.modifier == 6)
			return (print_o(format, va_arg(varlist, size_t)));
	}
	return (-1);
}
