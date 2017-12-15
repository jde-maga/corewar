/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:28:51 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/20 21:08:21 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	free_env(t_env *env)
{
	free(env->arena->zone);
	free(env->arena);
	free(env->player_list);
	free(env->process_list);
	free(env->display);
	free(env);
}

void		free_memory(t_env *env)
{
	int i;

	i = env->arena->process_amount - 1;
	while (i >= 0)
	{
		free(env->process_list[i]->reg);
		free(env->process_list[i]);
		i--;
	}
	i = env->arena->player_amount - 1;
	while (i >= 0)
	{
		free(env->player_list[i]->name);
		free(env->player_list[i]->instructions);
		free(env->player_list[i]);
		i--;
	}
	i = MEM_SIZE - 1;
	while (i >= 0)
	{
		free(env->display[i]);
		i--;
	}
	free_env(env);
}
