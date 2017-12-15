/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:32:56 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/10 17:46:49 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	get_alive_number(t_env *env)
{
	int alive;
	int i;

	alive = env->arena->player_amount;
	i = 0;
	while (env->player_list[i])
	{
		if (!env->player_list[i]->isalive || env->player_list[i]->isalive == -1)
			alive--;
		i++;
	}
	return (alive);
}

static void	get_winner(t_env *env)
{
	int i;

	i = 0;
	while (env->player_list[i])
	{
		if (env->player_list[i]->isalive == 1)
		{
			if (!DISPLAY)
				ft_printf("le joueur %d(%s) a gagne\n",
						env->player_list[i]->number, env->player_list[i]->name);
			else
				mvwprintw(env->w_menu, 64, 1, "Le joueur %d(%s) a gagne",
						env->player_list[i]->number, env->player_list[i]->name);
			if (DISPLAY)
				wrefresh(env->w_menu);
			free_memory(env);
			exit(0);
		}
		i++;
	}
}

static void	destroy_player(t_env *env, int i)
{
	int j;

	j = env->arena->process_amount - 1;
	while (j != -1)
	{
		if (env->process_list[j]->master_id == i)
			env->process_list[j]->wait_time = -1;
		j--;
	}
	j = 0;
	env->player_list[i]->isalive = -1;
}

void		live_check(t_env *env)
{
	int i;
	int alive;

	i = 0;
	if (!(alive = get_alive_number(env)))
	{
		if (!DISPLAY)
			ft_printf("tout les joueurs sont morts !\n");
		else
			mvwprintw(env->w_menu, 64, 1, "tout les joueurs sont morts !");
		wrefresh(env->w_menu);
		free_memory(env);
		exit(0);
	}
	else if (alive == 1)
		get_winner(env);
	else
		while (env->player_list[i])
		{
			if (env->player_list[i]->isalive == 1)
				env->player_list[i]->isalive = 0;
			else if (env->player_list[i]->isalive == 0)
				destroy_player(env, i);
			i++;
		}
}
