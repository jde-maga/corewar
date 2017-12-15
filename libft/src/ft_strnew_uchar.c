/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_uchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 18:23:15 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:20:07 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

unsigned char	*ft_strnew_uchar(size_t size)
{
	unsigned char	*otp;
	size_t			i;

	if ((otp = (unsigned char *)malloc(sizeof(*otp) * (size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		otp[i] = 0;
		i++;
	}
	otp[i] = 0;
	return (otp);
}
