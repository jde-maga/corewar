/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:50:09 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/19 11:58:55 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*flag_parser(char *s, t_printf_format *format, va_list varlist)
{
	while (ft_strchr(FLAG_LETTERS, *s))
	{
		if (*s == '0')
			format->flags.zero = 1;
		else if (*s == '-')
			format->flags.minus = 1;
		else if (*s == '+')
			format->flags.plus = 1;
		else if (*s == ' ')
			format->flags.space = 1;
		else if (*s == '#')
			format->flags.hashtag = 1;
		else if (*s == '*')
			format->pad_size = va_arg(varlist, int);
		if (format->pad_size < 0)
		{
			format->flags.minus = 1;
			format->pad_size = -(format->pad_size);
		}
		s++;
	}
	return (s);
}

char	*pad_parser(char *s, t_printf_format *format)
{
	format->pad_size = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	return (s);
}

char	*precision_parser(char *s, t_printf_format *format, va_list varlist)
{
	s++;
	if (*s == '*')
	{
		format->precision_size = va_arg(varlist, int);
		if (format->precision_size < 0)
			format->precision_size = -1;
		s++;
		while (*s == '*')
		{
			(void)va_arg(varlist, int);
			s++;
		}
		return (s);
	}
	format->precision_size = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	return (s);
}

char	*modifier_parser(char *s, t_printf_format *format)
{
	if (*s == 'h')
	{
		format->modifier = 2;
		s++;
		if (*s == 'h')
			format->modifier = 1;
		else
			s--;
	}
	if (*s == 'l')
	{
		format->modifier = 3;
		s++;
		if (*s == 'l')
			format->modifier = 4;
		else
			s--;
	}
	if (*s == 'j')
		format->modifier = 5;
	if (*s == 'z')
		format->modifier = 6;
	return (++s);
}

char	*string_parser(char *s, t_printf_format *format, va_list varlist)
{
	ftprintf_struct_init(format);
	if (ft_strchr(FLAG_LETTERS, *s))
		s = flag_parser(s, format, varlist);
	if (ft_strchr(PAD_LETTERS, *s))
		s = pad_parser(s, format);
	if (*s == '.')
		s = precision_parser(s, format, varlist);
	else
		format->precision_size = -1;
	if (ft_strchr(MODIFIER_LETTERS, *s))
		s = modifier_parser(s, format);
	if (ft_strchr(TYPE_LETTERS, *s))
		format->type = *s;
	else
		format->type = -1;
	if (format->precision_size != -1 && ft_strchr(NUMBER_TYPES, format->type))
		format->flags.zero = 0;
	return (s);
}
