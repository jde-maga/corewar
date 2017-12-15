/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itab_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:59:03 by mdamesto          #+#    #+#             */
/*   Updated: 2016/02/14 18:10:21 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_itab_set(int size)
{
	int	**tab;
	int	i;

	i = -1;
	tab = (int**)malloc(sizeof(int*) * size);
	while (++i < size)
		tab[i] = NULL;
	return (tab);
}
