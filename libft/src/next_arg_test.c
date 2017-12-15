/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_arg_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:49:54 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:51:43 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		test_next_arg(char *ipt_string, va_list varlist)
{
	t_printf_format	format;
	wint_t			buf;

	while (*ipt_string != '%' && *ipt_string)
		ipt_string++;
	if (*ipt_string == '%')
	{
		ipt_string++;
		ipt_string = string_parser(ipt_string, &format, varlist);
		if (format.type == 'C' || (format.type == 'c' && format.modifier == 3))
		{
			buf = va_arg(varlist, wint_t);
			if (buf > 1114111)
				return (1);
			if (buf >= 55296 && buf <= 57343)
				return (1);
		}
		else
			(void)va_arg(varlist, int);
	}
	return (0);
}
