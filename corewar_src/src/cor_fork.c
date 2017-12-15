/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:56:32 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/10 18:41:29 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int					forkcount(void)
{
	static int	fork_count;
	static int	fork_size;

	if (!fork_count)
	{
		fork_size = MAX_PLAYERS;
		fork_count = MAX_PLAYERS;
	}
	else
		fork_count++;
	if (fork_size == fork_count)
	{
		fork_size = fork_size * 2;
		return (fork_size);
	}
	return (0);
}

static t_process	*fork_process(t_env *env, int arg1)
{
	t_process *fork;

	fork = process_init(CUR_PROC->master, CUR_PROC->master_id);
	fork->carry = CUR_PROC->carry;
	fork->wait_time = 799;
	fork->pc = MODFIX(CUR_PROC->pc + (arg1 % IDX_MOD), MEM_SIZE);
	fork->reg = ft_memcpy(fork->reg, CUR_PROC->reg, sizeof(int) * REG_NUMBER);
	return (fork);
}

int					cor_fork(t_env *env, int pc)
{
	int arg1;
	int fork_count;

	arg1 = get_direct_short(ZONE, pc) % IDX_MOD;
	pc = (pc + 2) % MEM_SIZE;
	env->process_list[env->arena->process_amount] = fork_process(env, arg1);
	if ((fork_count = forkcount()))
		env->process_list = realloc(env->process_list,
						sizeof(t_process *) * (fork_count + 2));
	env->arena->process_amount++;
	env->process_list[env->arena->process_amount] = NULL;
	env->display[MODFIX(CUR_PROC->pc + (arg1 % IDX_MOD), MEM_SIZE)]->ispc = 1;
	env->display[MODFIX(CUR_PROC->pc + (arg1 % IDX_MOD), MEM_SIZE)]->forked =
																		799;
	env->display[MODFIX(CUR_PROC->pc + (arg1 % IDX_MOD), MEM_SIZE)]->update =
																		1;
	CUR_PROC->wait_time = 799;
	return (pc);
}
