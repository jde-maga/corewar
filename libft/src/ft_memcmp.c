/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:17:09 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/25 23:58:45 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char a;
	unsigned char b;

	while (n > 0)
	{
		a = *(unsigned char *)s1;
		b = *(unsigned char *)s2;
		if (a != b)
			return (a - b);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
