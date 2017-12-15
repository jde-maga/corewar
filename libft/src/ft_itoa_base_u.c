/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:38:55 by mdamesto          #+#    #+#             */
/*   Updated: 2016/01/21 15:51:40 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_size_u(unsigned long long int n, int base)
{
	size_t r;

	r = 0;
	while (n != 0)
	{
		n = n / base;
		r++;
	}
	return (r);
}

char	*ft_itoa_base_u(unsigned long long int n, int base)
{
	char				*tmp;
	size_t				s;
	unsigned long long	nb;

	s = get_size_u(n, base);
	tmp = ft_strnew(s);
	nb = n;
	while (s)
	{
		if (nb % base <= 9)
			tmp[s - 1] = nb % base + '0';
		else
			tmp[s - 1] = nb % base - 10 + 'a';
		nb = nb / base;
		s--;
	}
	return (tmp);
}
