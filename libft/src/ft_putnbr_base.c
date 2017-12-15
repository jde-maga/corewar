/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:17:32 by mdamesto          #+#    #+#             */
/*   Updated: 2015/12/15 19:09:16 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int n, int base)
{
	if (base != 10)
		n = (unsigned long)n;
	if (n == -2147483648)
		ft_putstr("-2147483648");
	if (n == -2147483648)
		return ;
	if (n < 0)
		write(1, "-", 1);
	if (n < 0)
		n = -n;
	if (n >= base)
	{
		ft_putnbr_base(n / base, base);
		if ((n % base) <= 9)
			ft_putchar((n % base) + '0');
		else
			ft_putchar((n % base) + 'W');
	}
	else
	{
		if ((n % base) <= 9)
			ft_putchar((n % base) + '0');
		else
			ft_putchar((n % base) + 'W');
	}
}
