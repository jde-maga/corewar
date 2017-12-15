/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ulong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:39:15 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:27:57 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_itoa_ulong_size(unsigned long n)
{
	int otp;

	otp = 1;
	while (n >= 10)
	{
		n /= 10;
		otp++;
	}
	return (otp);
}

char			*ft_itoa_ulong(unsigned long n)
{
	int				i;
	int				size;
	char			*otp;
	unsigned long	bufn;

	bufn = n;
	i = 0;
	size = ft_itoa_ulong_size(bufn);
	if ((otp = (char *)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	while (size)
	{
		otp[i] = (bufn % 10) + 48;
		bufn /= 10;
		size--;
		i++;
	}
	otp[i] = 0;
	ft_strrev(otp);
	return (otp);
}
