/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:00:45 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/28 15:33:45 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*c;
	char			*r;

	if (f == NULL)
		return (NULL);
	i = 0;
	c = (char *)ft_memalloc(ft_strlen(s));
	r = c;
	while (*s)
	{
		*c = f(i, *s);
		c++;
		s++;
		i++;
	}
	return (r);
}
