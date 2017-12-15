/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:11:24 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/04 15:42:24 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		u_undefined_behavior(t_printf_format format)
{
	if (BYPASS_UNDEFINED_BEHAVIOR)
		return (0);
	if (format.flags.plus)
		return (1);
	if (format.flags.space)
		return (1);
	if (format.flags.hashtag)
		return (1);
	return (0);
}

int		parser_u(t_printf_format format, va_list varlist)
{
	if (u_undefined_behavior(format))
		return (-1);
	else
	{
		if (format.type == 'U')
			return (print_u(format, va_arg(varlist, unsigned long)));
		if (!format.modifier)
			return (print_u(format, va_arg(varlist, unsigned int)));
		if (format.modifier == 1)
			return (print_u(format, (unsigned char)va_arg(varlist, int)));
		if (format.modifier == 2)
			return (print_u(format, (unsigned short)va_arg(varlist, int)));
		if (format.modifier == 3)
			return (print_u(format, va_arg(varlist, unsigned long)));
		if (format.modifier == 4)
			return (print_u(format, va_arg(varlist, unsigned long long)));
		if (format.modifier == 5)
			return (print_u(format, va_arg(varlist, uintmax_t)));
		if (format.modifier == 6)
			return (print_u(format, va_arg(varlist, size_t)));
	}
	return (-1);
}
