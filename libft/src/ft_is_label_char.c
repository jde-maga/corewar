/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_label_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:52:54 by jclerc            #+#    #+#             */
/*   Updated: 2017/03/20 18:59:57 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_label_char(char c)
{
	int			i;
	const char	*label_char = "abcdefghijklmnopqrstuvwxyz_0123456789";

	i = -1;
	while (label_char[++i])
	{
		if (label_char[i] == c)
			return (1);
	}
	return (0);
}
