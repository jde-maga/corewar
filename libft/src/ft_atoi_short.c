/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:11:04 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/20 18:52:43 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short	ft_atoi_short(const char *str)
{
	int			s;
	long int	r;

	s = 1;
	r = 0;
	while (*str == '\t' || *str == '\f' || *str == '\n' || *str == '\r' ||
*str == '\v' || *str == ' ' || *str == ' ')
		str++;
	if (*str == '-')
		s = -s;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str) > 0)
	{
		r = r * 10 + *str++ - '0';
		if (r > 32767 || r < -32768)
			r = (short)r;
	}
	if (s < 0)
		r = -r;
	return ((short)r);
}
