/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:57:58 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/25 21:06:11 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	f;

	i = 0;
	f = c;
	while (*s)
	{
		s++;
		i++;
	}
	while (i >= 0)
	{
		if (*s == f)
			return ((char *)s);
		i--;
		s--;
	}
	if (f == '\0')
		return ((char *)s);
	return (NULL);
}
