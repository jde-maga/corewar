/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 19:11:01 by mdamesto          #+#    #+#             */
/*   Updated: 2016/01/21 15:50:46 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(long int n)
{
	char c;

	if (n >= 16)
	{
		ft_puthex(n / 16);
		if ((n % 16) <= 9)
			c = ((n % 16) + '0');
		else
			c = (n % 16) + 'W';
		if (n < 0)
			c = ~c;
		ft_putchar(c);
	}
	else
	{
		if ((n % 16) <= 9)
			c = ((n % 16) + '0');
		else
			c = (n % 16) + 'W';
		if (n < 0)
			c = c;
		ft_putchar(c);
	}
}
