/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:02:38 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/25 23:23:54 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		while (s2[j] == s1[i + j])
		{
			if (s2[j + 1] == '\0')
			{
				s = (char *)&s1[i];
				return ((char *)s);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
