/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_store.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:04:21 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/10 18:43:01 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	apply_st_zone(t_env *env, int arg1, int arg2)
{
	int value;
	int position;

	value = swap_bytes(CUR_PROC->reg[arg1 - 1]);
	position = MODFIX((CUR_PROC->pc + (arg2 % IDX_MOD)), MEM_SIZE);
	ZONE[position % MEM_SIZE] = (value & 0xff000000) >> 24;
	ZONE[(position + 1) % MEM_SIZE] = (value & 0x00ff0000) >> 16;
	ZONE[(position + 2) % MEM_SIZE] = (value & 0x0000ff00) >> 8;
	ZONE[(position + 3) % MEM_SIZE] = (value & 0x000000ff);
	env->display[position % MEM_SIZE]->champion = CUR_PROC->master_id;
	env->display[(position + 1) % MEM_SIZE]->champion = CUR_PROC->master_id;
	env->display[(position + 2) % MEM_SIZE]->champion = CUR_PROC->master_id;
	env->display[(position + 3) % MEM_SIZE]->champion = CUR_PROC->master_id;
	env->display[position % MEM_SIZE]->value = (value & 0xff000000) >> 24;
	env->display[(position + 1) % MEM_SIZE]->value = (value & 0x00ff0000) >> 16;
	env->display[(position + 2) % MEM_SIZE]->value = (value & 0x0000ff00) >> 8;
	env->display[(position + 3) % MEM_SIZE]->value = (value & 0x000000ff);
	env->display[position % MEM_SIZE]->recent_display = 10;
	env->display[(position + 1) % MEM_SIZE]->recent_display = 10;
	env->display[(position + 2) % MEM_SIZE]->recent_display = 10;
	env->display[(position + 3) % MEM_SIZE]->recent_display = 10;
	env->display[position % MEM_SIZE]->update = 11;
	env->display[(position + 1) % MEM_SIZE]->update = 1;
	env->display[(position + 2) % MEM_SIZE]->update = 1;
	env->display[(position + 3) % MEM_SIZE]->update = 1;
}

static int	get_variable_1(int param, int *pc, t_env *env, int *arg1)
{
	if (((param & 192) >> 6) == REG_CODE)
	{
		if (ZONE[*pc] - 1 < 0 || ZONE[*pc] - 1 >= REG_NUMBER)
			return (1);
		else
		{
			*arg1 = ZONE[*pc];
			*pc = (*pc + 1) % MEM_SIZE;
		}
	}
	else
		return (-10);
	return (0);
}

static int	get_variable_2(int param, int *pc, t_env *env, int *arg2)
{
	if (((param & 48) >> 4) == IND_CODE)
	{
		*arg2 = get_direct_short(ZONE, *pc);
		*pc = (*pc + 2) % MEM_SIZE;
	}
	else if (((param & 48) >> 4) == REG_CODE)
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

int			cor_st(t_env *env, int param, int pc)
{
	int arg1;
	int arg2;
	int kill_op;

	kill_op = 0;
	if ((kill_op += get_variable_1(param, &pc, env, &arg1)) < 0)
		return ((CUR_PROC->pc + 1) % MEM_SIZE);
	if ((kill_op += get_variable_2(param, &pc, env, &arg2)) < 0)
		return ((CUR_PROC->pc + 1) % MEM_SIZE);
	CUR_PROC->wait_time = 5;
	if (kill_op)
		return (pc);
	if (((param & 48) >> 4) == IND_CODE)
		apply_st_zone(env, arg1, arg2);
	else
		CUR_PROC->reg[arg2 - 1] = CUR_PROC->reg[arg1 - 1];
	return (pc);
}
