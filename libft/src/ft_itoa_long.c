/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoav2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:39:15 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:27:02 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int				ft_itoa_size(unsigned long n)
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

static long				ft_itoa_timesten(int size)
{
	unsigned long c;

	c = 1;
	while (size)
	{
		c *= 10;
		size--;
	}
	return (c / 10);
}

static unsigned long	negative_check(long n, int *i)
{
	if (n < 0)
	{
		(*i)++;
		return (-n);
	}
	else
		return (n);
}

char					*ft_itoa_long(long n)
{
	int				i;
	int				size;
	char			*otp;
	unsigned long	bufn;

	i = 0;
	bufn = negative_check(n, &i);
	size = ft_itoa_size(bufn);
	if ((otp = (char *)malloc(sizeof(char) * size + 1 + i)) == NULL)
		return (NULL);
	if (i)
		otp[0] = '-';
	while (size)
	{
		otp[i] = (bufn / ft_itoa_timesten(size)) % 10 + 48;
		size--;
		i++;
	}
	otp[i] = 0;
	return (otp);
}
