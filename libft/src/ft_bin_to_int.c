/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:51:27 by jclerc            #+#    #+#             */
/*   Updated: 2017/03/20 18:52:00 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_bin_to_int(char *str)
{
	int len;
	int ret;
	int mult;

	len = ft_strlen(str) - 1;
	ret = 0;
	mult = 1;
	while (len >= 0)
	{
		ret += (str[len--] - '0') * mult;
		mult = mult * 2;
	}
	return (ret);
}
