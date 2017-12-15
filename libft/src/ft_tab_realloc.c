/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 20:38:04 by mdamesto          #+#    #+#             */
/*   Updated: 2016/02/14 18:11:33 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tab_realloc(char **tab, int size)
{
	char	**ret;
	int		i;

	i = 0;
	ret = (char**)malloc(sizeof(char *) * (ft_tab_len(tab) + size + 1));
	while (tab[i])
	{
		ret[i] = ft_strnew(ft_strlen(tab[i]) + 1);
		ft_strcpy(ret[i], tab[i]);
		i++;
	}
	ft_tab_free(tab);
	while (size >= 0)
	{
		ret[i + size] = NULL;
		size--;
	}
	return (ret);
}
