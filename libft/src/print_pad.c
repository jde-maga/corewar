/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:41:12 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:35:34 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char		*get_pad_string(int pad_size, int zpad)
{
	char	*e;
	int		i;

	i = 0;
	e = ft_strnew(pad_size);
	while (i < pad_size)
	{
		if (zpad)
			e[i] = '0';
		else
			e[i] = ' ';
		i++;
	}
	return (e);
}

void			get_pad(int pad_size, int zpad, char **str)
{
	char *buf;

	buf = get_pad_string(pad_size, zpad);
	ft_strcat(*str, buf);
	free(buf);
}
