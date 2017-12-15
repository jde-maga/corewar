/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:23:10 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/09 16:22:57 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	get_variable_1(int param, int *pc, t_env *env, int *arg1)
{
	if (((param & 192) >> 6) == REG_CODE)
	{
		if (ZONE[*pc] - 1 < 0 || ZONE[*pc] - 1 >= REG_NUMBER)
		{
			return (1);
		}
		else
		{
			*arg1 = swap_bytes(CUR_PROC->reg[ZONE[*pc] - 1]);
			*pc = (*pc + 1) % MEM_SIZE;
		}
	}
	else
		return (-10);
	return (0);
}

int			cor_aff(t_env *env, int param, int pc)
{
	int				arg1;
	unsigned char	buf;
	int				kill_op;

	(void)param;
	kill_op = 0;
	if ((kill_op += get_variable_1(param, &pc, env, &arg1)) < 0)
		return ((CUR_PROC->pc + 1) % MEM_SIZE);
	CUR_PROC->wait_time = 2;
	if (kill_op)
		return (pc);
	buf = MODFIX(arg1 % 256, 256);
	if (!DISPLAY)
		write(1, &buf, 1);
	return (pc);
}
