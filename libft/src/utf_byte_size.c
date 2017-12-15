/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf_byte_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 18:20:49 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:46:27 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		utf_byte_size(unsigned int c)
{
	int otp;

	otp = 0;
	while (c)
	{
		c /= 2;
		otp++;
	}
	if (otp <= 7)
		return (1);
	if (otp <= 11)
		return (2);
	if (otp <= 16)
		return (3);
	return (4);
}
