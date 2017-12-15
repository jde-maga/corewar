/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:15:11 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/10 17:55:47 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

t_player	*player_init(void)
{
	t_player *player;

	player = ft_memalloc(sizeof(t_player));
	player->number = 0;
	player->id = 0;
	player->name = ft_strnew(128);
	player->instructions = ft_memalloc(sizeof(unsigned char) * CHAMP_MAX_SIZE);
	player->instructions_size = 0;
	player->isalive = 0;
	return (player);
}

t_process	*process_init(int master, int master_id)
{
	t_process	*process;
	static int	id;

	process = ft_memalloc(sizeof(t_process));
	process->id = id;
	process->pc = 0;
	process->carry = 0;
	process->master = master;
	process->master_id = master_id;
	process->wait_time = 0;
	id++;
	process->reg = ft_memalloc(sizeof(int) * REG_NUMBER);
	return (process);
}

t_arena		*arena_init(void)
{
	t_arena	*arena;

	arena = ft_memalloc(sizeof(t_arena));
	arena->current_cycle = 0;
	arena->process_amount = 0;
	arena->player_amount = 0;
	arena->current_process = 0;
	arena->zone = ft_memalloc(sizeof(unsigned char *) * MEM_SIZE);
	arena->cycle_to_die = CYCLE_TO_DIE;
	arena->live_cycle = 0;
	arena->live_call = 0;
	arena->max_checks = 0;
	return (arena);
}

t_env		*env_init(void)
{
	t_env	*env;
	int		i;

	i = 0;
	env = ft_memalloc(sizeof(t_env));
	env->arena = arena_init();
	env->player_list = ft_memalloc(sizeof(t_player *) * (MAX_PLAYERS + 1));
	env->display = ft_memalloc(sizeof(t_display *) * MEM_SIZE);
	while (i != MEM_SIZE)
	{
		env->display[i] = display_init();
		i++;
	}
	env->process_list = ft_memalloc(sizeof(t_process *) * (MAX_PLAYERS + 1));
	env->dump = -1;
	return (env);
}

t_display	*display_init(void)
{
	t_display *display;

	display = ft_memalloc(sizeof(t_display));
	display->value = 0;
	display->champion = 0;
	display->recent_display = 0;
	display->ispc = 0;
	display->update = 1;
	return (display);
}
