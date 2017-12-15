/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:51:57 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/25 14:43:54 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	f;

	f = c;
	while (*s)
	{
		if (*s == f)
			return ((char *)s);
		s++;
	}
	if (f == '\0')
		return ((char*)s);
	return (NULL);
}
