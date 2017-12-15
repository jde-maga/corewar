/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:48:29 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/30 19:57:19 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_sets(int num)
{
	char	*s;
	int		n;

	n = 0;
	if (num < 0)
	{
		n++;
		num = -num;
	}
	while (num != 0)
	{
		num = num / 10;
		n++;
	}
	s = ft_strnew(n);
	return (s);
}

static	int	ft_isneg(int n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

static char	*ft_error(int n)
{
	char *c;

	if (n == -2147483648)
	{
		c = ft_strnew(11);
		ft_strcpy(c, "-2147483648");
		return (c);
	}
	if (n == 0)
	{
		c = ft_strnew(1);
		ft_strcpy(c, "0");
		return (c);
	}
	else
		return (NULL);
}

static char	*ft_fill(char *tmp, int i, int n)
{
	char	*c;
	char	*cc;
	int		s;

	s = ft_isneg(n);
	c = ft_sets(n);
	cc = c;
	n = n * ft_isneg(n);
	if (s < 0)
	{
		*c = '-';
		c++;
	}
	while (i > 0)
	{
		*c = *tmp;
		tmp--;
		c++;
		i--;
	}
	return (cc);
}

char		*ft_itoa(int n)
{
	char	*tmp;
	int		i;
	int		m;

	m = n;
	i = 0;
	if (ft_error(n) != NULL)
		return (ft_error(n));
	tmp = ft_sets(n);
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		*tmp = n % 10 + '0';
		n = n / 10;
		tmp++;
		i++;
	}
	tmp--;
	return (ft_fill(tmp, i, m));
}
