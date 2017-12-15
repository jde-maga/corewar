/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:12:52 by mdamesto          #+#    #+#             */
/*   Updated: 2016/02/14 18:35:29 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include <stdint.h>

# define EBDARG			1
# define EOPEN			2
# define EMALLOC    	3
# define EGNL 			4
# define EEMPTYFILE 	5
# define ENONAME		6
# define ENOCOM			7
# define EPARSING		8
# define EBDINST		9
# define E_ARG_NB		10
# define E_BD_REG		11
# define E_BD_ARG		12
# define E_BD_DIR		13
# define E_BD_IND		14
# define E_UK_LBL		15
# define E_BD_LBL		16
# define E_BD_CHP		17
# define E_NM_LEN		18
# define E_CM_LEN		19
# define E_LST_LINE		20
# define E_CHMP_NULL	21

typedef struct		s_label
{
	char			*name;
	int				adress;
	struct s_label	*next;
}					t_label;

typedef struct		s_instr
{
	char			*content;
	int				adress;
	int				line;
	struct s_instr	*next;
}					t_inst;

typedef struct		s_env
{
	t_header		*header;
	t_label			*labels;
	t_inst			*inst;
	char			*filename;
	int				fd;
	int				line_nb;
	uint32_t		c_adress;
	int				add_to_adress;
	char			*line;
	char			**data;
}					t_env;

void				inst_to_env(char *inst, char *args_code, char **args);
char				**init_args(void);
void				live_zjump_fork_lfork(char *data, char *inst, size_t siz);
void				add_sub(char *data, char *inst);
void				ld_lld(char *data, char *inst);
void				or_xor_and(char *data, char *inst);
void				ldi_lldi(char *data, char *inst);
void				sti(char *data, char *inst);
void				st(char *data, char *inst);
void				aff(char *data, char *inst);
void				ft_error(int code);
int					gnl(void);
int					check_empty_line(char *line);
void				parsing_champion(t_env *env);
void				init_env(char *filename);
t_env				*get_env(t_env *env);
void				free_env(void);
void				get_name(t_env *env);
void				get_comment(t_env *env);
void				print_labels(t_env *env);
void				add_label(t_env *env, char *label);
void				replace_labels(t_env *env);
int					check_arg(char *arg);
char				*get_dir(char *arg, int size);
char				*get_reg(char *arg);
char				*get_ind(char *arg);
void				print_name_comment(t_env *env);
void				print_add_inst(char *inst, char *args_code, char **args);
void				print_labels(t_env *env);
void				print_inst(t_env *env);
void				print_champ(char **tab, char *final);
void				create_champion(t_env *env);
char				*str_to_hex(char *str);
char				*ret_to_oct(char *tmp, int oct_nb);
void				inst_switch(char **data);
void				get_arg_reg_dir4_ind(char *split, \
char				**args, char **tab_args_code, int arg_nb);
void				get_arg_reg_dir2_ind(char *split, \
					char **args, char **tab_args_code, int arg_nb);
void				get_arg_reg_dir2(char *split, \
					char **args, char **tab_args_code, int arg_nb);
void				get_arg_reg_dir4(char *split, \
					char **args, char **tab_args_code, int arg_nb);
char				**split_and_trim(char *data);
void				get_inst(t_env *env);

#endif
