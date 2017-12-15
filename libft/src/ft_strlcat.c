/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 21:11:33 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/30 18:57:46 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_return(size_t i, size_t j, char *dst)
{
	*dst = '\0';
	return (i + j);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		n;

	n = size;
	i = 0;
	j = ft_strlen(src);
	while (*dst && n--)
	{
		dst++;
		i++;
	}
	n = size - i;
	if (n == 0)
		return (i + ft_strlen(src));
	while (*src)
	{
		if (n > 1)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	return (ft_return(i, j, dst));
}
