/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:34:37 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/10 18:42:49 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	apply_sti_zone(t_env *env, int arg1, int arg2, int arg3)
{
	int pos;

	pos = MODFIX(CUR_PROC->pc + ((arg2 + arg3) % IDX_MOD), MEM_SIZE);
	ZONE[pos % MEM_SIZE] = (arg1 & 0xff000000) >> 24;
	ZONE[(pos + 1) % MEM_SIZE] = (arg1 & 0x00ff0000) >> 16;
	ZONE[(pos + 2) % MEM_SIZE] = (arg1 & 0x0000ff00) >> 8;
	ZONE[(pos + 3) % MEM_SIZE] = (arg1 & 0x000000ff);
	env->display[pos % MEM_SIZE]->value = (arg1 & 0xff000000) >> 24;
	env->display[(pos + 1) % MEM_SIZE]->value = (arg1 & 0x00ff0000) >> 16;
	env->display[(pos + 2) % MEM_SIZE]->value = (arg1 & 0x0000ff00) >> 8;
	env->display[(pos + 3) % MEM_SIZE]->value = (arg1 & 0x000000ff);
	env->display[pos % MEM_SIZE]->champion = CUR_PROC->master_id;
	env->display[(pos + 1) % MEM_SIZE]->champion = CUR_PROC->master_id;
	env->display[(pos + 2) % MEM_SIZE]->champion = CUR_PROC->master_id;
	env->display[(pos + 3) % MEM_SIZE]->champion = CUR_PROC->master_id;
	env->display[pos % MEM_SIZE]->recent_display = 10;
	env->display[(pos + 1) % MEM_SIZE]->recent_display = 10;
	env->display[(pos + 2) % MEM_SIZE]->recent_display = 10;
	env->display[(pos + 3) % MEM_SIZE]->recent_display = 10;
	env->display[pos % MEM_SIZE]->update = 1;
	env->display[(pos + 1) % MEM_SIZE]->update = 1;
	env->display[(pos + 2) % MEM_SIZE]->update = 1;
	env->display[(pos + 3) % MEM_SIZE]->update = 1;
}

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
		*arg2 = get_direct_short(ZONE, *pc);
		*pc = (*pc + 2) % MEM_SIZE;
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
			*arg3 = swap_bytes(CUR_PROC->reg[ZONE[*pc] - 1]);
			*pc = (*pc + 1) % MEM_SIZE;
		}
	}
	else if (((param & 12) >> 2) == DIR_CODE)
	{
		*arg3 = get_direct_short(ZONE, *pc);
		*pc = (*pc + 2) % MEM_SIZE;
	}
	else
		return (-10);
	return (0);
}

int			cor_sti(t_env *env, int param, int pc)
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
	CUR_PROC->wait_time = 25;
	if (kill_op)
		return (pc);
	apply_sti_zone(env, arg1, arg2, arg3);
	return (pc);
}
