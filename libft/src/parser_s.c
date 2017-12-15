/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:11:24 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 16:54:47 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		s_undefined_behavior(t_printf_format format)
{
	if (BYPASS_UNDEFINED_BEHAVIOR)
		return (0);
	if (format.flags.plus)
		return (1);
	if (format.flags.space)
		return (1);
	if (format.flags.hashtag)
		return (1);
	if (format.flags.zero)
		return (1);
	if (format.modifier && format.modifier != 3)
		return (1);
	if (format.type == 'S' && format.precision_size > 0)
		return (1);
	return (0);
}

int		parser_s(t_printf_format format, va_list varlist)
{
	if (s_undefined_behavior(format))
		return (-1);
	else
	{
		if (format.type == 'S')
			return (print_ls(&format, (wint_t*)va_arg(varlist, wchar_t *)));
		if (!format.modifier)
			return (print_s(format, va_arg(varlist, char *)));
		if (format.modifier == 3)
			return (print_ls(&format, (wint_t*)va_arg(varlist, wchar_t *)));
	}
	return (-1);
}
