/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_live.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:44:03 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/10 18:41:47 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	apply_livecheck(t_env *env, int arg1)
{
	int i;

	i = 0;
	while (env->player_list[i])
	{
		if (env->player_list[i]->number == arg1
			&& env->player_list[i]->isalive != -1)
		{
			if (!DISPLAY)
				ft_printf("un processus dit que le joueur %d(%s) est en vie\n",
							env->player_list[i]->number,
							env->player_list[i]->name);
			env->player_list[i]->isalive = 1;
		}
		i++;
	}
}

int			cor_live(t_env *env, int pc)
{
	int arg1;

	arg1 = get_direct(ZONE, pc);
	pc = (pc + 4) % MEM_SIZE;
	apply_livecheck(env, arg1);
	env->arena->live_call++;
	CUR_PROC->wait_time = 10;
	return (pc);
}
