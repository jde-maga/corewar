/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:57:10 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 18:03:54 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		general_undefined_behavior(t_printf_format format)
{
	if (BYPASS_UNDEFINED_BEHAVIOR)
		return (0);
	if (format.flags.zero && format.flags.minus)
		return (1);
	if (format.flags.plus && format.flags.space)
		return (1);
	return (0);
}

static int		conv_parser(t_printf_format format, va_list varlist)
{
	if (general_undefined_behavior(format))
		return (-1);
	if (format.flags.zero && format.flags.minus)
		format.flags.zero = 0;
	if (format.flags.plus && format.flags.space)
		format.flags.space = 0;
	if (format.type == 'c' || format.type == '%' || format.type == 'C')
		return (parser_c(format, varlist));
	if (format.type == 'd' || format.type == 'i' || format.type == 'D')
		return (parser_d(format, varlist));
	if (format.type == 's' || format.type == 'S')
		return (parser_s(format, varlist));
	if (format.type == 'u' || format.type == 'U')
		return (parser_u(format, varlist));
	if (format.type == 'o' || format.type == 'O')
		return (parser_o(format, varlist));
	if (format.type == 'x' || format.type == 'X')
		return (parser_x(format, varlist));
	if (format.type == 'p')
		return (parser_p(format, varlist));
	return (-1);
}

static int		print_nonarg(char *str)
{
	int i;

	i = 0;
	while (str[i] != '%' && str[i])
		i++;
	write(1, str, i);
	return (i);
}

int				print_printf(char **ipt_string, t_printf_format *format,
					int *next_arg_checked, va_list *varlist)
{
	int i;
	int parser_check;

	if (**ipt_string == '%')
	{
		*next_arg_checked = 0;
		(*ipt_string)++;
		*ipt_string = string_parser(*ipt_string, format, *varlist);
		if ((parser_check = conv_parser(*format, *varlist)) == -1)
			return (-1);
		(*ipt_string)++;
		return (parser_check);
	}
	else if (ft_isascii(**ipt_string))
	{
		i = print_nonarg(*ipt_string);
		(*ipt_string) += i;
		return (i);
	}
	return (0);
}

int				ft_printf(char *ipt_string, ...)
{
	va_list			varlist;
	va_list			buflist;
	int				i;
	int				next_arg_checked;
	t_printf_format	format;

	va_start(varlist, ipt_string);
	va_copy(buflist, varlist);
	i = 0;
	next_arg_checked = 0;
	while (*ipt_string)
	{
		if (!next_arg_checked)
		{
			next_arg_checked = 1;
			if (test_next_arg(ipt_string, buflist))
				return (-1);
		}
		i += print_printf(&ipt_string, &format, &next_arg_checked, &varlist);
	}
	va_end(varlist);
	va_end(buflist);
	return (i);
}
