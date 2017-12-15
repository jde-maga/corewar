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

char	*ft_strcut_end(char *str, int n)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = ft_strlen(str) - n;
	tmp = ft_strnew(len);
	while (i < len)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	free(str);
	return (tmp);
}
