/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:13:20 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/28 15:22:03 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_sub_siz(const char *str)
{
	const char	*tmp;

	tmp = str;
	while (*tmp && *tmp != ' ' && *tmp != '	')
		tmp++;
	return (tmp - str);
}

static size_t	get_tab_row(const char *s)
{
	size_t	n_sep;
	int		word_before;

	word_before = 0;
	n_sep = 0;
	while (*s)
	{
		if (*s == ' ' || *s == '	')
		{
			while (*s == ' ' || *s == '	')
				s++;
			if (word_before && *s)
				n_sep++;
			word_before = 0;
		}
		else
		{
			word_before = 1;
			s++;
		}
	}
	return (n_sep + 1);
}

char			**ft_strsplit_space(char *s)
{
	char	**out;
	size_t	n;
	size_t	row;
	size_t	siz;

	if (!s)
		return (NULL);
	row = get_tab_row(s);
	if (!(out = malloc(sizeof(char *) * (row + 1))))
		return (NULL);
	n = 0;
	while (*s == ' ' || *s == '	')
		s++;
	while (n < row)
	{
		siz = get_sub_siz(s);
		out[n++] = siz ? ft_strsub(s, 0, siz) : NULL;
		s += siz;
		while (*s == ' ' || *s == '	')
			s++;
	}
	out[n] = NULL;
	return (out);
}
