/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:22:42 by mdamesto          #+#    #+#             */
/*   Updated: 2016/01/21 15:51:04 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *c;
	char *r;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	c = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	r = c;
	if (c == NULL)
		return (NULL);
	while (*s1)
	{
		*c = *s1;
		c++;
		s1++;
	}
	while (*s2)
	{
		*c = *s2;
		c++;
		s2++;
	}
	*c = '\0';
	return (r);
}

char	*ft_strjoin_f(char *s1, char *s2, int code)
{
	int		i;
	int		j;
	char	*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ret[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ret[j++] = s2[i++];
	ret[j] = '\0';
	if (code == 1 || code == 3)
		free(s1);
	if (code == 2 || code == 3)
		free(s2);
	return (ret);
}
