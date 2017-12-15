/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:36:47 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/19 11:58:05 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ftprintf_struct_init(t_printf_format *format)
{
	format->flags.zero = 0;
	format->flags.minus = 0;
	format->flags.plus = 0;
	format->flags.space = 0;
	format->flags.hashtag = 0;
	format->pad_size = 0;
	format->precision_size = 0;
	format->modifier = 0;
	format->type = 0;
	format->hide_print = 0;
	format->nwcard = 0;
}
