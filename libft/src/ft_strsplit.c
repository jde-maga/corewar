/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtassett <mtassett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 00:12:34 by mtassett          #+#    #+#             */
/*   Updated: 2016/11/20 16:21:26 by mtassett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_sub_siz(const char *str, char c)
{
	const char	*tmp;

	tmp = str;
	while (*tmp != c && *tmp)
		tmp++;
	return (tmp - str);
}

static size_t	get_tab_row(const char *s, char c)
{
	size_t	n_sep;
	int		word_before;

	word_before = 0;
	n_sep = 0;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
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

char			**ft_strsplit(const char *s, char c)
{
	char	**out;
	size_t	n;
	size_t	row;
	size_t	siz;

	if (!s)
		return (NULL);
	row = get_tab_row(s, c);
	if (!(out = malloc(sizeof(char *) * (row + 1))))
		return (NULL);
	n = 0;
	while (*s == c)
		s++;
	while (n < row)
	{
		siz = get_sub_siz(s, c);
		out[n++] = siz ? ft_strsub(s, 0, siz) : NULL;
		s += siz;
		while (*s == c)
			s++;
	}
	out[n] = NULL;
	return (out);
}
