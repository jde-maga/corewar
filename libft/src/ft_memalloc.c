/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:49:21 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/28 15:45:09 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *cmem;

	if (!size)
		return (NULL);
	cmem = (char *)malloc(size);
	if (cmem == NULL)
		return (NULL);
	ft_bzero(cmem, size);
	return (cmem);
}
