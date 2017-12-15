/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:53:12 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/20 18:53:13 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnstr(unsigned char *str, size_t size, int hex)
{
	size_t		i;
	char const	base[] = "0123456789abcdef";

	i = -1;
	while (++i < size)
	{
		if (hex)
		{
			if (i % 2 == 0 && i != 0)
				ft_putchar(' ');
			ft_putchar(base[str[i] / 16]);
			ft_putchar(base[str[i] % 16]);
		}
		else
		{
			if (!ft_isprint(str[i]))
				ft_putchar('.');
			else
				ft_putchar(str[i]);
		}
	}
}

static int		ft_putnbrhex(unsigned long nb, size_t length)
{
	int			size;
	char const	base[] = "0123456789abcdef";

	size = 1;
	if (nb >= 16)
		size += ft_putnbrhex(nb / 16, --length);
	else if (length > 0)
	{
		size += length - 1;
		while (--length > 0)
			ft_putchar('0');
	}
	ft_putchar(base[nb % 16]);
	return (size);
}

static void		print_addr(void *addr, size_t size)
{
	size_t i;

	i = 0;
	ft_putnbrhex((unsigned long)addr, (sizeof(addr) == 4) ? 8 : 12);
	ft_putchar(':');
	ft_putchar('\t');
	ft_putnstr((addr), size, 1);
	if (size != 16)
		while (i < 16 - size)
		{
			if (i % 2 == 1)
				ft_putchar(' ');
			write(1, "  ", 2);
			i++;
		}
	ft_putchar('\t');
	ft_putnstr((addr), size, 0);
	ft_putchar('\n');
}

void			*ft_print_memory(void *addr, size_t size)
{
	void *data;

	data = addr;
	if (!size)
		return (0);
	while (size > 16)
	{
		print_addr(data, 16);
		size -= 16;
		data += 16;
	}
	print_addr(data, (int)size);
	return (addr);
}
