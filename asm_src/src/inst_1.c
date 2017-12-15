/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:12:39 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/18 18:12:40 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	live_zjump_fork_lfork(char *data, char *inst, size_t siz)
{
	char	**args;
	char	**split;

	args = init_args();
	split = split_and_trim(data);
	if (!split[0] || split[1])
		ft_error(E_ARG_NB);
	if (check_arg(split[0]) == 2)
		args[0] = get_dir(split[0], siz);
	else
		ft_error(E_BD_ARG);
	if (split)
		free(split);
	inst_to_env(inst, NULL, args);
}

void	add_sub(char *data, char *inst)
{
	char	**args;
	char	*args_code;
	char	**split;

	args_code = "54";
	args = init_args();
	split = split_and_trim(data);
	if (!split[0] || !split[1] || !split[2] || split[3])
		ft_error(E_ARG_NB);
	if (check_arg(split[0]) == 1 \
		&& check_arg(split[1]) == 1 && check_arg(split[2]) == 1)
	{
		args[0] = get_reg(split[0]);
		args[1] = get_reg(split[1]);
		args[2] = get_reg(split[2]);
	}
	else
		ft_error(E_BD_ARG);
	if (split)
		free(split);
	inst_to_env(inst, args_code, args);
}

void	or_xor_and(char *data, char *inst)
{
	char	**args;
	char	**tab_args_code;
	char	*args_code;
	char	**split;

	tab_args_code = ft_tab_set(4, 2);
	ft_strcpy(tab_args_code[3], "00");
	args = init_args();
	split = split_and_trim(data);
	if (!split[0] || !split[1] || !split[2] || split[3])
		ft_error(E_ARG_NB);
	get_arg_reg_dir4_ind(split[0], args, tab_args_code, 0);
	get_arg_reg_dir4_ind(split[1], args, tab_args_code, 1);
	if (check_arg(split[2]) == 1)
	{
		args[2] = get_reg(split[2]);
		ft_strcpy(tab_args_code[2], "01");
	}
	else
		ft_error(E_BD_ARG);
	args_code = convert_hex_octnb(ft_bin_to_int(ft_tab_join(tab_args_code)), 1);
	ft_tab_free(tab_args_code);
	if (split)
		free(split);
	inst_to_env(inst, args_code, args);
}

void	aff(char *data, char *inst)
{
	char	**args;
	char	**split;
	char	*args_code;

	args = init_args();
	split = split_and_trim(data);
	args_code = "40";
	if (!split[0] || split[1])
		ft_error(E_ARG_NB);
	if (check_arg(split[0]) == 1)
		args[0] = get_reg(split[0]);
	else
		ft_error(E_BD_ARG);
	if (split)
		free(split);
	inst_to_env(inst, args_code, args);
}
