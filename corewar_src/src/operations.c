/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:16:21 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/08 17:06:30 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int		operation_2(t_env *env, int opcode, int param, int pc)
{
	if (opcode == 11)
		pc = cor_sti(env, param, pc);
	else if (opcode == 12)
		pc = cor_fork(env, pc);
	else if (opcode == 13)
		pc = cor_lld(env, param, pc);
	else if (opcode == 14)
		pc = cor_lldi(env, param, pc);
	else if (opcode == 15)
		pc = cor_lfork(env, pc);
	else if (opcode == 16)
		pc = cor_aff(env, param, pc);
	else
		pc = (CUR_PROC->pc + 1) % MEM_SIZE;
	return (pc);
}

int				operation(t_env *env, int opcode, int param, int pc)
{
	if (opcode == 1)
		pc = cor_live(env, pc);
	else if (opcode == 2)
		pc = cor_ld(env, param, pc);
	else if (opcode == 3)
		pc = cor_st(env, param, pc);
	else if (opcode == 4)
		pc = cor_add(env, param, pc);
	else if (opcode == 5)
		pc = cor_sub(env, param, pc);
	else if (opcode == 6)
		pc = cor_and(env, param, pc);
	else if (opcode == 7)
		pc = cor_or(env, param, pc);
	else if (opcode == 8)
		pc = cor_xor(env, param, pc);
	else if (opcode == 9)
		pc = cor_zjmp(env, pc);
	else if (opcode == 10)
		pc = cor_ldi(env, param, pc);
	else
		return (operation_2(env, opcode, param, pc));
	return (pc);
}
