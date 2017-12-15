/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmv_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:27:15 by mdamesto          #+#    #+#             */
/*   Updated: 2016/01/22 15:36:07 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rmv_space(char *str)
{
	int		i;
	int		len;
	char	*ret;

	if (!str)
		return (NULL);
	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '	' && str[i] != '\n')
			len++;
	}
	ret = ft_strnew(len);
	len = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '	' && str[i] != '\n')
			ret[len++] = str[i];
	}
	return (ret);
}

char	*ft_rmv_space_f(char *str)
{
	int		i;
	int		len;
	char	*ret;

	if (!str)
		return (NULL);
	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '	' && str[i] != '\n')
			len++;
	}
	ret = ft_strnew(len);
	len = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '	' && str[i] != '\n')
			ret[len++] = str[i];
	}
	free(str);
	return (ret);
}
