/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:15:57 by mdamesto          #+#    #+#             */
/*   Updated: 2016/01/18 16:48:50 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		get_size(long long int n, int base)
{
	size_t	r;
	long	nb;

	r = 0;
	nb = n;
	if (n < 0)
		r++;
	while (nb != 0)
	{
		nb = nb / base;
		r++;
	}
	return (r);
}

char		*max_0(long long int n)
{
	char *tmp;

	if (n == 0)
	{
		tmp = ft_strnew(1);
		ft_strcpy(tmp, "0");
		return (tmp);
	}
	else
	{
		tmp = ft_strnew(20);
		ft_strcpy(tmp, "9223372036854775808");
		return (tmp);
	}
}

char		*ft_itoa_base(long long int n, int base)
{
	char		*tmp;
	size_t		s;
	long long	nb;

	if (n == (-9223372036854775807 - 1) || n == 0)
		return (max_0(n));
	s = get_size(n, base);
	tmp = ft_strnew(s);
	nb = n;
	if (n < 0)
		nb = -nb;
	while (s)
	{
		if (nb % base <= 9)
			tmp[s - 1] = nb % base + '0';
		else
			tmp[s - 1] = nb % base - 10 + 'a';
		nb = nb / base;
		s--;
	}
	if (n < 0)
		tmp[0] = '-';
	return (tmp);
}
