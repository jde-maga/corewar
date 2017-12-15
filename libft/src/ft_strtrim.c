/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:29:21 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/30 20:05:20 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_start(const char *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*c;
	char	*r;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = ft_start(s);
	j = 0;
	while (s[j])
		j++;
	if (i == j--)
		return (ft_strnew(0));
	while (s[j] == ' ' || s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	c = ft_strnew(j - i + 1);
	r = c;
	while (i <= j)
	{
		*r = s[i];
		r++;
		i++;
	}
	return (c);
}

char		*ft_strtrim_f(char *s)
{
	char	*c;
	char	*r;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = ft_start(s);
	j = 0;
	while (s[j])
		j++;
	if (i == j--)
		return (ft_strnew(0));
	while (s[j] == ' ' || s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	c = ft_strnew(j - i + 1);
	r = c;
	while (i <= j)
	{
		*r = s[i];
		r++;
		i++;
	}
	free(s);
	return (c);
}
