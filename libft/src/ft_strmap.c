/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:57:20 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/27 23:52:59 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *c;
	char *r;

	if (f == NULL)
		return (NULL);
	c = (char*)ft_memalloc(ft_strlen(s));
	r = c;
	while (*s)
	{
		*c = f(*s);
		c++;
		s++;
	}
	return (r);
}
