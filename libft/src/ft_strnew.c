/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:41:28 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/27 23:20:35 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*cmem;
	size_t	i;

	cmem = (char *)malloc(sizeof(char) * (size + 1));
	if (cmem == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		cmem[i] = '\0';
		i++;
	}
	cmem[i] = '\0';
	return ((void *)cmem);
}
