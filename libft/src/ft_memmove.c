/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:03:17 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/27 22:58:35 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*cdst;
	char	*csrc;
	char	*tmp;

	i = 0;
	cdst = (char *)dst;
	csrc = (char *)src;
	tmp = ft_strnew(len);
	while (i < len)
	{
		tmp[i] = csrc[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		cdst[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (dst);
}
