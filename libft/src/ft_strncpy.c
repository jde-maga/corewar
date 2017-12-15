/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:34:00 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/27 23:27:46 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*r;

	r = dst;
	while (*src && n != 0)
	{
		*dst = *src;
		dst++;
		src++;
		n--;
	}
	while (n != 0)
	{
		*dst = '\0';
		n--;
		dst++;
	}
	return (r);
}
