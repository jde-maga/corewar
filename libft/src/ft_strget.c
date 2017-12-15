/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:42:18 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/20 18:42:19 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strget(char *str, int s, int e)
{
	char	*ret;
	int		i;

	i = 0;
	if (!str || !(ret = ft_strnew(e - s)))
		return (NULL);
	while (s < e)
		ret[i++] = str[s++];
	return (ret);
}

char	*ft_strget_f(char *str, int s, int e)
{
	char	*ret;
	int		i;

	i = 0;
	if (!str || !(ret = ft_strnew(e - s)))
		return (NULL);
	while (s < e)
		ret[i++] = str[s++];
	free(str);
	return (ret);
}
