/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:41:12 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:43:45 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char		*get_precision_string(int precision_size)
{
	char	*e;
	int		i;

	e = ft_strnew(precision_size);
	i = 0;
	while (i < precision_size)
	{
		e[i] = '0';
		i++;
	}
	return (e);
}

void			get_precision(int precision_size, char **str)
{
	char *buf;

	buf = get_precision_string(precision_size);
	ft_strcat(*str, buf);
	free(buf);
}
