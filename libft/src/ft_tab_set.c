/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:14:10 by mdamesto          #+#    #+#             */
/*   Updated: 2016/01/22 17:14:53 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tab_set(int y, int x)
{
	char	**ret;
	int		i;

	i = -1;
	ret = (char**)malloc(sizeof(char *) * (y + 1));
	ret[y] = NULL;
	if (x > 0)
		while (++i < y)
			ret[i] = ft_strnew(x);
	else
	{
		while (++i < y)
			ret[i] = NULL;
	}
	return (ret);
}
