/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 18:23:24 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:49:07 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_utf_one_bit(unsigned int c, unsigned char **str)
{
	unsigned char *e;

	e = malloc(2);
	e[0] = (unsigned char)c;
	e[1] = 0;
	ft_strcat_uchar(*str, e);
	free(e);
}

void	get_utf_two_bits(unsigned int c, unsigned char **str)
{
	unsigned char *e;

	e = malloc(3);
	e[0] = ((c & 1984) >> 6) | 192;
	e[1] = (c & 63) | 128;
	e[2] = 0;
	ft_strcat_uchar(*str, e);
	free(e);
}

void	get_utf_three_bits(unsigned int c, unsigned char **str)
{
	unsigned char *e;

	e = malloc(4);
	e[0] = ((c & 61440) >> 12) | 224;
	e[1] = ((c & 4032) >> 6) | 128;
	e[2] = (c & 63) | 128;
	e[3] = 0;
	ft_strcat_uchar(*str, e);
	free(e);
}

void	get_utf_four_bits(unsigned int c, unsigned char **str)
{
	unsigned char *e;

	e = malloc(5);
	e[0] = ((c & 1835008) >> 18) | 240;
	e[1] = ((c & 258048) >> 12) | 128;
	e[2] = ((c & 4032) >> 6) | 128;
	e[3] = (c & 63) | 128;
	e[4] = 0;
	ft_strcat_uchar(*str, e);
	free(e);
}

void	get_utf_char(unsigned int c, unsigned char **str)
{
	if (ft_binary_size(c) <= 7)
		get_utf_one_bit(c, str);
	else if (ft_binary_size(c) <= 11)
		get_utf_two_bits(c, str);
	else if (ft_binary_size(c) <= 16)
		get_utf_three_bits(c, str);
	else
		get_utf_four_bits(c, str);
}
