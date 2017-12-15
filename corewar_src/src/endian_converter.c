/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:31:09 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/07 14:59:54 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		swap_bytes(int arg)
{
	int byte1;
	int byte2;
	int byte3;
	int byte4;
	int otp;

	byte1 = (arg & 0xFF000000) >> 24;
	byte2 = (arg & 0x00FF0000) >> 16;
	byte3 = (arg & 0x0000FF00) >> 8;
	byte4 = (arg & 0x000000FF);
	otp = byte1;
	otp += byte2 << 8;
	otp += byte3 << 16;
	otp += byte4 << 24;
	return (otp);
}
