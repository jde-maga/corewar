/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:13:26 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/18 18:13:26 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		norme1(t_env *env)
{
	if (!ft_strncmp("add", env->line, 3))
	{
		add_sub(ft_strcut_beg(env->line, 3), "04");
		return (1);
	}
	else if (!ft_strncmp("sub", env->line, 3))
	{
		add_sub(ft_strcut_beg(env->line, 3), "05");
		return (1);
	}
	else if (!ft_strncmp("and", env->line, 3))
	{
		or_xor_and(ft_strcut_beg(env->line, 3), "06");
		return (1);
	}
	else if (!ft_strncmp("xor", env->line, 3))
	{
		or_xor_and(ft_strcut_beg(env->line, 3), "08");
		return (1);
	}
	return (0);
}

static int		norme2(t_env *env)
{
	if (!ft_strncmp("ldi", env->line, 3))
	{
		ldi_lldi(ft_strcut_beg(env->line, 3), "0a");
		return (1);
	}
	else if (!ft_strncmp("sti", env->line, 3))
	{
		sti(ft_strcut_beg(env->line, 3), "0b");
		return (1);
	}
	else if (!ft_strncmp("lld", env->line, 3))
	{
		ld_lld(ft_strcut_beg(env->line, 3), "0d");
		return (1);
	}
	else if (!ft_strncmp("aff", env->line, 3))
	{
		aff(ft_strcut_beg(env->line, 3), "10");
		return (1);
	}
	return (0);
}

static int		norme3(t_env *env, int len)
{
	if (len > 1)
	{
		if (!ft_strncmp("ld", env->line, 2))
		{
			ld_lld(ft_strcut_beg(env->line, 2), "02");
			return (1);
		}
		else if (!ft_strncmp("st", env->line, 2))
		{
			st(ft_strcut_beg(env->line, 2), "03");
			return (1);
		}
		else if (!ft_strncmp("or", env->line, 2))
		{
			or_xor_and(ft_strcut_beg(env->line, 2), "07");
			return (1);
		}
	}
	return (0);
}

static int		norme0(t_env *env, int len)
{
	if (len > 3)
	{
		if (!ft_strncmp("fork", env->line, 4))
		{
			live_zjump_fork_lfork(ft_strcut_beg(env->line, 4), "0c", 2);
			return (1);
		}
		else if (!ft_strncmp("live", env->line, 4))
		{
			live_zjump_fork_lfork(ft_strcut_beg(env->line, 4), "01", 4);
			return (1);
		}
		else if (!ft_strncmp("zjmp", env->line, 4))
		{
			live_zjump_fork_lfork(ft_strcut_beg(env->line, 4), "09", 2);
			return (1);
		}
		else if (!ft_strncmp("lldi", env->line, 4))
		{
			ldi_lldi(ft_strcut_beg(env->line, 4), "0e");
			return (1);
		}
	}
	return (0);
}

void			get_inst(t_env *env)
{
	int len;

	env->line = ft_strtrim(env->line);
	len = ft_strlen(env->line);
	if (len > 4)
	{
		if (!ft_strncmp("lfork", env->line, 5))
			return (live_zjump_fork_lfork(\
				ft_strcut_beg(env->line, 5), "0f", 2));
	}
	if (norme0(env, len) == 1)
		return ;
	if (len > 2)
	{
		if (norme1(env) == 1)
			return ;
		if (norme2(env) == 1)
			return ;
	}
	if (norme3(env, len) == 1)
		return ;
	ft_error(EBDINST);
}
