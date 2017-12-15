/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_lld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:14:27 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/07 16:18:27 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	get_variable_1(int param, int *pc, t_env *env, int *arg1)
{
	if (((param & 192) >> 6) == IND_CODE)
	{
		*arg1 = get_indirect(ZONE, *pc, CUR_PROC->pc);
		*pc = (*pc + 2) % MEM_SIZE;
	}
	else if (((param & 192) >> 6) == DIR_CODE)
	{
		*arg1 = get_direct(ZONE, *pc);
		*pc = (*pc + 4) % MEM_SIZE;
	}
	else
		return (-10);
	return (0);
}

static int	get_variable_2(int param, int *pc, t_env *env, int *arg2)
{
	if (((param & 48) >> 4) == REG_CODE)
	{
		if (ZONE[*pc] - 1 < 0 || ZONE[*pc] - 1 >= REG_NUMBER)
			return (1);
		else
		{
			*arg2 = ZONE[*pc];
			*pc = (*pc + 1) % MEM_SIZE;
		}
	}
	else
		return (-10);
	return (0);
}

int			cor_lld(t_env *env, int param, int pc)
{
	int arg1;
	int arg2;
	int kill_op;

	kill_op = 0;
	if ((kill_op += get_variable_1(param, &pc, env, &arg1)) < 0)
		return ((CUR_PROC->pc + 1) % MEM_SIZE);
	if ((kill_op += get_variable_2(param, &pc, env, &arg2)) < 0)
		return ((CUR_PROC->pc + 1) % MEM_SIZE);
	CUR_PROC->wait_time = 10;
	if (kill_op)
		return (pc);
	CUR_PROC->reg[arg2 - 1] = swap_bytes(arg1);
	if (!arg1)
		CUR_PROC->carry = 1;
	else
		CUR_PROC->carry = 0;
	return (pc);
}
