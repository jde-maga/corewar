/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:54:36 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/20 20:58:53 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	create_starting_process(t_env *env)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (env->player_list[i])
	{
		env->process_list[i]->pc = j;
		env->display[j]->ispc = 1;
		env->player_list[i]->id = i + 1;
		while (k != env->player_list[i]->instructions_size)
		{
			env->arena->zone[j] = env->player_list[i]->instructions[k];
			env->display[j]->value = env->arena->zone[j];
			env->display[j]->champion = i + 1;
			j++;
			k++;
		}
		i++;
		j = (MEM_SIZE / env->arena->player_amount) * i;
		k = 0;
	}
}

static void	inject_players(t_env *env)
{
	int i;

	i = 0;
	while (env->player_list[i])
	{
		env->process_list[i] = process_init(env->player_list[i]->number, i + 1);
		env->process_list[i]->reg[0] = swap_bytes(env->player_list[i]->number);
		env->arena->process_amount++;
		i++;
	}
	create_starting_process(env);
}

static void	error_handle(int j, t_env *env)
{
	if (j == -1)
		ft_printf("dump error\n");
	else if (j == -2)
		ft_printf("-n error\n");
	else if (j == -3)
		ft_printf("file error\n");
	else if (j == -4)
		ft_printf("too much players\n");
	else
		return ;
	free_memory(env);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_env	*env;
	int		j;

	env = env_init();
	if (argc == 1)
	{
		ft_printf("no commmands\n");
		return (0);
	}
	j = arg_parser(argc, argv, env);
	error_handle(j, env);
	inject_players(env);
	if (DISPLAY)
		init_display(env);
	process_turn(env);
	return (0);
}
