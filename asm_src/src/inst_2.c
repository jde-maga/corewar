/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:12:45 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/18 18:12:52 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	norme(char *split, char **args_code, char **args)
{
	if (check_arg(split) == 1)
		args[0] = get_reg(split);
	else if (check_arg(split) == 2)
	{
		*args_code = "90";
		args[0] = get_dir(split, 4);
	}
	else if (check_arg(split) == 3)
	{
		*args_code = "d0";
		args[0] = get_ind(split);
	}
	else
		ft_error(E_BD_ARG);
}

void	ld_lld(char *data, char *inst)
{
	char	**args;
	char	*args_code;
	char	**split;

	args_code = "50";
	args = init_args();
	split = split_and_trim(data);
	if (!split[0] || !split[1] || split[2])
		ft_error(E_ARG_NB);
	norme(split[0], &args_code, args);
	if (check_arg(split[1]) == 1)
		args[1] = get_reg(split[1]);
	else
		ft_error(E_BD_ARG);
	if (split)
		free(split);
	inst_to_env(inst, args_code, args);
}

void	ldi_lldi(char *data, char *inst)
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
	get_arg_reg_dir2_ind(split[0], args, tab_args_code, 0);
	get_arg_reg_dir2(split[1], args, tab_args_code, 1);
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

void	st(char *data, char *inst)
{
	char	**args;
	char	*args_code;
	char	**split;

	args_code = "50";
	args = init_args();
	split = split_and_trim(data);
	if (!split[0] || !split[1] || split[2])
		ft_error(E_ARG_NB);
	if (check_arg(split[0]) == 1)
		args[0] = get_reg(split[0]);
	else
		ft_error(E_BD_ARG);
	if (check_arg(split[1]) == 1)
		args[1] = get_reg(split[1]);
	else if (check_arg(split[1]) == 3)
	{
		args_code = "70";
		args[1] = get_ind(split[1]);
	}
	else
		ft_error(E_BD_ARG);
	if (split)
		free(split);
	inst_to_env(inst, args_code, args);
}

void	sti(char *data, char *inst)
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
	if (check_arg(split[0]) == 1)
	{
		args[0] = get_reg(split[0]);
		ft_strcpy(tab_args_code[0], "01");
	}
	else
		ft_error(E_BD_ARG);
	get_arg_reg_dir2_ind(split[1], args, tab_args_code, 1);
	get_arg_reg_dir2(split[2], args, tab_args_code, 2);
	args_code = convert_hex_octnb(ft_bin_to_int(ft_tab_join(tab_args_code)), 1);
	ft_tab_free(tab_args_code);
	if (split)
		free(split);
	inst_to_env(inst, args_code, args);
}
