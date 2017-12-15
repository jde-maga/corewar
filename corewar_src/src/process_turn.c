/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_turn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:43:50 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/20 20:49:23 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	hexa_dump(t_env *env)
{
	int i;

	i = 0;
	while (i != MEM_SIZE)
	{
		if (ZONE[i] < 16)
			ft_printf("0");
		ft_printf("%x ", ZONE[i]);
		if ((i + 1) % 64 == 0)
			ft_printf("\n");
		i++;
	}
	ft_printf("\n");
	free_memory(env);
	exit(0);
}

void		end_cycle(t_env *env)
{
	if (env->arena->current_cycle == env->dump)
		hexa_dump(env);
	if (DISPLAY)
		display(env);
	env->arena->current_cycle++;
	env->arena->live_cycle++;
	if (env->arena->live_cycle >= env->arena->cycle_to_die)
	{
		env->arena->max_checks++;
		if (env->arena->live_call >= NBR_LIVE ||
			env->arena->max_checks >= MAX_CHECKS)
		{
			env->arena->cycle_to_die -= CYCLE_DELTA;
			env->arena->max_checks = 0;
		}
		live_check(env);
		env->arena->live_call = 0;
		env->arena->live_cycle = 0;
		if (env->arena->cycle_to_die < 0)
			env->arena->cycle_to_die = 0;
	}
}

static void	play_turn(t_env *env)
{
	int opcode;
	int param;
	int pc;

	param = 0;
	pc = CUR_PROC->pc;
	opcode = ZONE[pc];
	pc = (pc + 1) % MEM_SIZE;
	if (!(opcode == 1 || opcode == 9 ||
		opcode == 12 || opcode == 15))
	{
		param = ZONE[pc % MEM_SIZE];
		pc = (pc + 1) % MEM_SIZE;
	}
	env->display[CUR_PROC->pc]->ispc = 0;
	env->display[CUR_PROC->pc]->update = 1;
	CUR_PROC->pc = operation(env, opcode, param, pc);
	env->display[CUR_PROC->pc]->ispc = 1;
	env->display[CUR_PROC->pc]->update = 1;
}

void		process_turn(t_env *env)
{
	while (1)
	{
		env->arena->current_process = env->arena->process_amount - 1;
		while (env->arena->current_process >= 0)
		{
			if (CUR_PROC->wait_time && CUR_PROC->wait_time != -1)
				CUR_PROC->wait_time--;
			if (!CUR_PROC->wait_time)
				play_turn(env);
			env->arena->current_process--;
		}
		end_cycle(env);
	}
}
