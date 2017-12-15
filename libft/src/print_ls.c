/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 15:22:22 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:56:05 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		calibrate_format_ls(t_printf_format *format, const wint_t *s)
{
	int get_precision_size;

	get_precision_size = 0;
	if (format->precision_size == -1 ||
		format->precision_size > ft_strlen_ls(s))
		format->precision_size = ft_strlen_ls(s);
	while (get_precision_size <= format->precision_size && *s)
	{
		get_precision_size += utf_byte_size(*s);
		s++;
	}
	if (get_precision_size > format->precision_size)
		get_precision_size -= utf_byte_size(*s);
	format->precision_size = get_precision_size;
	format->pad_size -= format->precision_size;
	if (format->pad_size < 0)
		format->pad_size = 0;
}

static int		putstr_ls_printf(const wchar_t *s, int size)
{
	int				i;
	unsigned char	*e;

	i = 0;
	e = ft_strnew_uchar(utf_byte_size(*s));
	while (size > 0)
	{
		get_utf_char((unsigned int)*s, &e);
		size -= utf_byte_size(*s);
		i += utf_byte_size(*s);
		s++;
		if (size - utf_byte_size(*s) < 0)
		{
			write(1, e, ft_strlen_uchar(e));
			free(e);
			return (i);
		}
	}
	write(1, e, ft_strlen_uchar(e));
	free(e);
	return (i);
}

static wint_t	*null_string(void)
{
	wint_t *str;

	str = malloc(sizeof(wint_t) * 7);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = 0;
	return (str);
}

int				print_ls(t_printf_format *format, wint_t *ls)
{
	int			ret;
	char		*bufpad;
	wint_t		*bufnull;

	bufnull = NULL;
	if (ls == NULL)
	{
		ls = null_string();
		bufnull = ls;
	}
	calibrate_format_ls(format, ls);
	if (format->flags.minus)
		ret = putstr_ls_printf((wchar_t*)ls, format->precision_size);
	if (format->pad_size)
	{
		bufpad = ft_strnew(format->pad_size);
		get_pad(format->pad_size, format->flags.zero, &bufpad);
		write(1, bufpad, format->pad_size);
		free(bufpad);
	}
	if (!format->flags.minus)
		ret = putstr_ls_printf((wchar_t*)ls, format->precision_size);
	if (bufnull)
		free(bufnull);
	return (ret + format->pad_size);
}
