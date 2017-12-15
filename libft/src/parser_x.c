/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:11:24 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/04 15:38:57 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		undefined_behavior_x(t_printf_format format)
{
	if (BYPASS_UNDEFINED_BEHAVIOR)
		return (0);
	if (format.flags.plus)
		return (1);
	if (format.flags.space)
		return (1);
	return (0);
}

char	ft_printf_hexa_table(int i, char type)
{
	if (i == 10)
		return (type == 'x' ? 'a' : 'A');
	if (i == 11)
		return (type == 'x' ? 'b' : 'B');
	if (i == 12)
		return (type == 'x' ? 'c' : 'C');
	if (i == 13)
		return (type == 'x' ? 'd' : 'D');
	if (i == 14)
		return (type == 'x' ? 'e' : 'E');
	if (i == 15)
		return (type == 'x' ? 'f' : 'F');
	return ((i % 16) + 48);
}

int		parser_x(t_printf_format format, va_list varlist)
{
	if (undefined_behavior_x(format))
		return (-1);
	else
	{
		if (!format.modifier)
			return (print_x(format, va_arg(varlist, unsigned int)));
		if (format.modifier == 1)
			return (print_x(format, (unsigned char)va_arg(varlist, int)));
		if (format.modifier == 2)
			return (print_x(format, (unsigned short)va_arg(varlist, int)));
		if (format.modifier == 3)
			return (print_x(format, va_arg(varlist, unsigned long)));
		if (format.modifier == 4)
			return (print_x(format, va_arg(varlist, unsigned long long)));
		if (format.modifier == 5)
			return (print_x(format, va_arg(varlist, uintmax_t)));
		if (format.modifier == 6)
			return (print_x(format, va_arg(varlist, size_t)));
	}
	return (-1);
}
