/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:54:15 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/20 21:57:39 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <libft.h>
# include <op.h>
# include <ncurses.h>

# define CUR_PROC env->process_list[env->arena->current_process]
# define ZONE env->arena->zone
# define DISPLAY 1
# define FASTDISPLAY 0
# define MODFIX(x, y) (((x) % (y)) < 0) ? ((x) % (y)) + (y) : (x) % (y)

typedef struct	s_process
{
	int	id;
	int	*reg;
	int	pc;
	int	carry;
	int	master;
	int	wait_time;
	int	master_id;
}				t_process;

typedef struct	s_player
{
	int				number;
	int				id;
	char			*name;
	int				isalive;
	unsigned char	*instructions;
	int				instructions_size;
}				t_player;

typedef struct	s_arena
{
	int				current_cycle;
	int				player_amount;
	int				process_amount;
	int				current_process;

	int				cycle_to_die;
	int				live_cycle;
	int				live_call;
	int				max_checks;
	unsigned char	*zone;
}				t_arena;

typedef struct	s_display
{
	unsigned char	value;
	short			champion;
	short			recent_display;
	short			ispc;
	int				forked;
	short			update;
}				t_display;

typedef struct	s_env
{
	t_player	**player_list;
	t_process	**process_list;
	t_arena		*arena;
	t_display	**display;
	int			dump;

	WINDOW		*w_main;
	WINDOW		*w_menu;
}				t_env;

t_player		*player_init();
t_process		*process_init(int master, int master_id);
t_arena			*arena_init();
t_env			*env_init();
t_display		*display_init();

void			init_display(t_env *env);

int				arg_parser(int ac, char **av, t_env *env);
t_player		*file_parser(int fd, t_env *env);

int				get_direct(unsigned char *zone, int pc);
int				get_indirect(unsigned char *zone, int pc, int refpc);
short			get_direct_short(unsigned char *zone, int pc);
int				get_indirect_idx(unsigned char *zone, int pc, int refpc);

int				operation(t_env *env, int opcode, int param, int pc);

void			live_check(t_env *env);

void			end_cycle(t_env *env);
void			process_turn(t_env *env);

void			free_memory(t_env *env);

int				forkcount(void);

int				cor_live(t_env *env, int pc);
int				cor_ld(t_env *env, int param, int pc);
int				cor_st(t_env *env, int param, int pc);
int				cor_add(t_env *env, int param, int pc);
int				cor_sub(t_env *env, int param, int pc);
int				cor_and(t_env *env, int param, int pc);
int				cor_or(t_env *env, int param, int pc);
int				cor_xor(t_env *env, int param, int pc);
int				cor_zjmp(t_env *env, int pc);
int				cor_ldi(t_env *env, int param, int pc);
int				cor_sti(t_env *env, int param, int pc);
int				cor_fork(t_env *env, int pc);
int				cor_lld(t_env *env, int param, int pc);
int				cor_lldi(t_env *env, int param, int pc);
int				cor_lfork(t_env *env, int pc);
int				cor_aff(t_env *env, int param, int pc);

int				swap_bytes(int arg);

void			init_display(t_env *env);
void			display(t_env *env);
void			end_display(t_env *env);

#endif
