/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_get_mult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:06:14 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/18 19:06:15 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_arg_reg_dir4_ind(char *split, char **args\
	, char **tab_args_code, int arg_nb)
{
	if (check_arg(split) == 1)
	{
		args[arg_nb] = get_reg(split);
		ft_strcpy(tab_args_code[arg_nb], "01");
	}
	else if (check_arg(split) == 2)
	{
		args[arg_nb] = get_dir(split, 4);
		ft_strcpy(tab_args_code[arg_nb], "10");
	}
	else if (check_arg(split) == 3)
	{
		args[arg_nb] = get_ind(split);
		ft_strcpy(tab_args_code[arg_nb], "11");
	}
	else
		ft_error(E_BD_ARG);
}

void	get_arg_reg_dir2_ind(char *split, char **args\
	, char **tab_args_code, int arg_nb)
{
	if (check_arg(split) == 1)
	{
		args[arg_nb] = get_reg(split);
		ft_strcpy(tab_args_code[arg_nb], "01");
	}
	else if (check_arg(split) == 2)
	{
		args[arg_nb] = get_dir(split, 2);
		ft_strcpy(tab_args_code[arg_nb], "10");
	}
	else if (check_arg(split) == 3)
	{
		args[arg_nb] = get_ind(split);
		ft_strcpy(tab_args_code[arg_nb], "11");
	}
	else
		ft_error(E_BD_ARG);
}

void	get_arg_reg_dir2(char *split, char **args\
	, char **tab_args_code, int arg_nb)
{
	if (check_arg(split) == 1)
	{
		args[arg_nb] = get_reg(split);
		ft_strcpy(tab_args_code[arg_nb], "01");
	}
	else if (check_arg(split) == 2)
	{
		args[arg_nb] = get_dir(split, 2);
		ft_strcpy(tab_args_code[arg_nb], "10");
	}
	else
		ft_error(E_BD_ARG);
}

void	get_arg_reg_dir4(char *split, char **args\
	, char **tab_args_code, int arg_nb)
{
	if (check_arg(split) == 1)
	{
		args[arg_nb] = get_reg(split);
		ft_strcpy(tab_args_code[arg_nb], "01");
	}
	else if (check_arg(split) == 2)
	{
		args[arg_nb] = get_dir(split, 4);
		ft_strcpy(tab_args_code[arg_nb], "10");
	}
	else
		ft_error(E_BD_ARG);
}
