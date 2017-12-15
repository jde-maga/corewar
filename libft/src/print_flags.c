/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:41:12 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:29:15 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		get_flags_size(t_printf_format *format, int positive)
{
	int i;

	i = 0;
	if (format->flags.plus && positive)
		i++;
	if (format->flags.space && positive)
		i++;
	if (format->flags.zero && !positive)
		i++;
	if (format->flags.hashtag)
		i++;
	if (format->flags.hashtag)
	{
		if (format->type == 'o' || format->type == 'O')
			i++;
		else if (format->type == 'x' || format->type == 'p')
			i += 2;
		else if (format->type == 'X')
			i += 2;
	}
	return (i);
}

static char		*get_flags_string(t_printf_format *format, int pos)
{
	char *e;

	e = ft_strnew(get_flags_size(format, pos));
	if (format->flags.plus && pos)
		ft_strcat(e, "+");
	if (format->flags.space && pos)
		ft_strcat(e, " ");
	if (!pos && format->flags.zero)
		ft_strcat(e, "-");
	if (format->flags.hashtag)
	{
		if (format->type == 'o' || format->type == 'O')
			ft_strcat(e, "0");
		else if (format->type == 'x' || format->type == 'p')
			ft_strcat(e, "0x");
		else if (format->type == 'X')
			ft_strcat(e, "0X");
	}
	return (e);
}

void			get_flags(t_printf_format *format, int pos, char **str)
{
	char *buf;

	buf = get_flags_string(format, pos);
	ft_strcat(*str, buf);
	free(buf);
}
