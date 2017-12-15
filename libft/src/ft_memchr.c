/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:08:19 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/30 13:37:19 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char l;
	char *sc;

	if (s == NULL)
		return (NULL);
	l = (unsigned char)c;
	sc = (char *)s;
	while (n > 0)
	{
		if (*sc == l)
			return ((void *)sc);
		n--;
		sc++;
	}
	return (NULL);
}
