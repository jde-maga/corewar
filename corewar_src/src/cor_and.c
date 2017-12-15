/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:33:02 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/07 16:04:02 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	get_variable_1(int param, int *pc, t_env *env, int *arg1)
{
	if (((param & 192) >> 6) == REG_CODE)
	{
		if (ZONE[*pc] - 1 < 0 || ZONE[*pc] - 1 >= REG_NUMBER)
			return (1);
		else
		{
			*arg1 = swap_bytes(CUR_PROC->reg[ZONE[*pc] - 1]);
			*pc = (*pc + 1) % MEM_SIZE;
		}
	}
	else if (((param & 192) >> 6) == IND_CODE)
	{
		*arg1 = get_indirect_idx(ZONE, *pc, CUR_PROC->pc);
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
			*arg2 = swap_bytes(CUR_PROC->reg[ZONE[*pc] - 1]);
			*pc = (*pc + 1) % MEM_SIZE;
		}
	}
	else if (((param & 48) >> 4) == IND_CODE)
	{
		*arg2 = get_indirect_idx(ZONE, *pc, CUR_PROC->pc);
		*pc = (*pc + 2) % MEM_SIZE;
	}
	else if (((param & 48) >> 4) == DIR_CODE)
	{
		*arg2 = get_direct(ZONE, *pc);
		*pc = (*pc + 4) % MEM_SIZE;
	}
	else
		return (-10);
	return (0);
}

static int	get_variable_3(int param, int *pc, t_env *env, int *arg3)
{
	if (((param & 12) >> 2) == REG_CODE)
	{
		if (ZONE[*pc] - 1 < 0 || ZONE[*pc] - 1 >= REG_NUMBER)
			return (1);
		else
		{
			*arg3 = ZONE[*pc];
			*pc = (*pc + 1) % MEM_SIZE;
		}
	}
	else
		return (-10);
	return (0);
}

int			cor_and(t_env *env, int param, int pc)
{
	int arg1;
	int arg2;
	int arg3;
	int kill_op;

	kill_op = 0;
	if ((kill_op += get_variable_1(param, &pc, env, &arg1)) < 0)
		return ((CUR_PROC->pc + 1) % MEM_SIZE);
	if ((kill_op += get_variable_2(param, &pc, env, &arg2)) < 0)
		return ((CUR_PROC->pc + 1) % MEM_SIZE);
	if ((kill_op += get_variable_3(param, &pc, env, &arg3)) < 0)
		return ((CUR_PROC->pc + 1) % MEM_SIZE);
	CUR_PROC->wait_time = 6;
	if (kill_op)
		return (pc);
	CUR_PROC->reg[arg3 - 1] = swap_bytes(arg1 & arg2);
	if (!(arg1 & arg2))
		CUR_PROC->carry = 1;
	else
		CUR_PROC->carry = 0;
	return (pc);
}
