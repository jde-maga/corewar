/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 14:16:32 by jde-maga          #+#    #+#             */
/*   Updated: 2016/06/30 19:36:24 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_isint(char *s)
{
	int		i;
	long	c;

	if (ft_strlen(s) == 1 && !ft_isdigit(s[0]))
		return (0);
	if (ft_strlen(s) > 11 || (ft_strlen(s) == 11
							&& (s[0] != '+' && s[0] != '-')))
		return (0);
	if (!ft_isdigit(s[0]) && s[0] != '+' && s[0] != '-')
		return (0);
	i = 1;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	c = ft_atoi_long(s);
	if (c > INT_MAX || c < INT_MIN)
		return (0);
	return (1);
}
