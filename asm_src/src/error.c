/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:12:23 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/18 18:12:31 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	norme2(int code)
{
	if (code == 4)
		ft_putstr_fd("gnl: read error\n", 2);
	else if (code == 5)
		ft_putstr_fd("Empty file\n", 2);
	else if (code == 6)
		ft_putstr_fd("Champion must have a name\n", 2);
	else if (code == 18)
	{
		ft_putstr_fd("Champion's name too long (max ", 2);
		ft_putstr_fd(ft_itoa(PROG_NAME_LENGTH), 2);
		ft_putstr_fd(":)\n", 2);
	}
	else if (code == 7)
		ft_putstr_fd("Champion must have a comment\n", 2);
	else if (code == 19)
	{
		ft_putstr_fd("Champion's comment too long (max ", 2);
		ft_putstr_fd(ft_itoa(COMMENT_LENGTH), 2);
		ft_putstr_fd(":)\n", 2);
	}
	else if (code == 21)
	{
		ft_putstr_fd("Champ have no instructions.", 2);
		ft_putstr_fd("\n", 2);
	}
}

void	norme3(int code, t_env *env)
{
	if (code == 8)
	{
		ft_putstr_fd("Synthax error on line ", 2);
		ft_putstr_fd(ft_itoa(env->line_nb), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(env->line, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (code == 9)
	{
		ft_putstr_fd("Invalid instruction on line ", 2);
		ft_putstr_fd(ft_itoa(env->line_nb), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(env->line, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (code == 10)
	{
		ft_putstr_fd("Wrong number of args for instruction on line ", 2);
		ft_putstr_fd(ft_itoa(env->line_nb), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(env->line, 2);
		ft_putstr_fd("\n", 2);
	}
}

void	norme4(int code, t_env *env)
{
	if (code == 11)
	{
		ft_putstr_fd("Unknow registre on line ", 2);
		ft_putstr_fd(ft_itoa(env->line_nb), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(env->line, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (code == 12)
	{
		ft_putstr_fd("Wrong arg on line ", 2);
		ft_putstr_fd(ft_itoa(env->line_nb), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(env->line, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (code == 13)
	{
		ft_putstr_fd("Wrong Direct value on line ", 2);
		ft_putstr_fd(ft_itoa(env->line_nb), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(env->line, 2);
		ft_putstr_fd("\n", 2);
	}
}

void	norme5(int code, t_env *env)
{
	if (code == 14)
	{
		ft_putstr_fd("Wrong Indirect value on line ", 2);
		ft_putstr_fd(ft_itoa(env->line_nb), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(env->line, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (code == 15)
	{
		ft_putstr_fd("Unknow label\n", 2);
	}
	else if (code == 16)
	{
		ft_putstr_fd("Bad label character on line ", 2);
		ft_putstr_fd(ft_itoa(env->line_nb), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(env->line, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (code == 20)
	{
		ft_putstr_fd("unexpected end of input", 2);
		ft_putstr_fd("\n", 2);
	}
}

void	ft_error(int code)
{
	t_env *env;

	if (code == 1 || code == 2 || code == 3 || code == 17)
	{
		if (code == 1)
			ft_putstr_fd("Invalid number of arguments\n", 2);
		else if (code == 2)
			ft_putstr_fd("Could not open the file\n", 2);
		else if (code == 3)
			ft_putstr_fd("Malloc failed\n", 2);
		else if (code == 17)
			ft_putstr_fd("Invalid file (must be \".s\")\n", 2);
		exit(code);
	}
	env = get_env(NULL);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(env->filename, 2);
	ft_putstr_fd(": ", 2);
	norme2(code);
	norme3(code, env);
	norme4(code, env);
	norme5(code, env);
	exit(code);
}
