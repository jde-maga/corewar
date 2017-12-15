/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut_beg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:43:15 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/27 23:46:48 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut_beg(char *str, int n)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(ft_strlen(str) - n);
	while (str[n])
	{
		tmp[i++] = str[n++];
	}
	tmp[i] = '\0';
	return (tmp);
}
