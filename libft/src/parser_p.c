/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 19:08:08 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/01 16:26:57 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		undefined_behavior_p(t_printf_format format)
{
	if (BYPASS_UNDEFINED_BEHAVIOR)
		return (0);
	if (format.flags.plus)
		return (1);
	if (format.flags.space)
		return (1);
	if (format.flags.zero)
		return (1);
	if (format.flags.hashtag)
		return (1);
	if (format.modifier)
		return (1);
	if (format.precision_size != -1)
		return (1);
	return (0);
}

int		parser_p(t_printf_format format, va_list varlist)
{
	if (undefined_behavior_p(format))
		return (-1);
	else
		return (print_p(format, (void *)va_arg(varlist, void *)));
}
