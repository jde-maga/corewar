/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:11:04 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/20 18:58:53 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_hex(const char *str)
{
	int r;

	r = 0;
	while (ft_ishex(*str))
	{
		if (*str >= '0' && *str <= '9')
			r = r * 16 + *str++ - '0';
		else if (*str >= 'A' && *str <= 'F')
			r = r * 16 + *str++ - 'A' + 10;
		else
			r = r * 16 + *str++ - 'a' + 10;
	}
	return (r);
}
