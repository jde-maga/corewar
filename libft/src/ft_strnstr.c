/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:13:08 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/27 23:27:00 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		while (s2[j] == s1[i + j])
		{
			if (s2[j + 1] == '\0')
				return ((char *)&s1[i]);
			if (i + j == n)
				return (NULL);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
