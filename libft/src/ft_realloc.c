/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:27:15 by mdamesto          #+#    #+#             */
/*   Updated: 2016/01/22 15:36:07 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, int size)
{
	char *tmp;

	tmp = str;
	str = ft_strnew(ft_strlen(tmp) + size);
	ft_strcmp(str, tmp);
	free(tmp);
	return (str);
}
