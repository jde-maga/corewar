/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:37:39 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/20 18:37:40 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tab_join(char **tab)
{
	int		i;
	char	*str;
	char	*tmp;

	str = ft_strnew(ft_strlen(tab[0]));
	ft_strcpy(str, tab[0]);
	i = 1;
	while (tab[i])
	{
		tmp = str;
		str = ft_strjoin(str, tab[i]);
		free(tmp);
		i++;
	}
	return (str);
}
