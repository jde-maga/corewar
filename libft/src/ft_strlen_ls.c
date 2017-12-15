/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 18:00:56 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/18 17:54:00 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strlen_ls(const wint_t *ls)
{
	size_t otp;

	otp = 0;
	while (*ls)
	{
		otp += utf_byte_size(*ls);
		ls++;
	}
	return (otp);
}
