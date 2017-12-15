/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istr_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:57:46 by mdamesto          #+#    #+#             */
/*   Updated: 2016/02/14 18:11:09 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_istr_set(int size)
{
	int *tab;
	int i;

	i = -1;
	tab = (int*)malloc(sizeof(int) * size);
	while (++i < size)
		tab[i] = 0;
	return (tab);
}
