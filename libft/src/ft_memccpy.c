/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:55:26 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/25 20:52:24 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dstchar;
	char	*srcchar;

	dstchar = dst;
	srcchar = (char *)src;
	i = 0;
	while (i < n)
	{
		dstchar[i] = srcchar[i];
		if (srcchar[i] == c)
		{
			i++;
			return (&dstchar[i]);
		}
		i++;
	}
	return (NULL);
}
