/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:13:43 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/27 23:56:11 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *c;
	char *r;

	if (s == NULL)
		return (NULL);
	c = ft_strnew(len);
	if (c == NULL)
		return (NULL);
	r = c;
	while (len > 0)
	{
		*c = s[start];
		c++;
		start++;
		len--;
	}
	return (r);
}
