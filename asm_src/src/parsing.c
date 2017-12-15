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

static	int		check_label(char *label)
{
	int i;

	i = 0;
	while (label[i] == ' ' || label[i] == '	')
		i++;
	while (label[++i])
	{
		if (!ft_is_label_char(label[i]))
			return (1);
	}
	return (0);
}

static	int		get_label(t_env *env)
{
	int		i;
	char	*label;

	i = -1;
	label = NULL;
	while (env->line[++i] && env->line[i] != LABEL_CHAR)
		;
	if (i == 0)
		ft_error(E_BD_LBL);
	if (env->line[i] == LABEL_CHAR)
		label = ft_strget(env->line, 0, i);
	if (label)
	{
		if (check_label(label))
			return (1);
		add_label(env, label);
		env->line = ft_strcut_f(env->line, 0, i + 1);
		if (check_empty_line(env->line))
			if (!gnl())
				return (0);
		get_label(env);
	}
	return (1);
}

void			parsing_champion(t_env *env)
{
	get_name(env);
	get_comment(env);
	while (gnl() > 0)
	{
		if (get_label(env))
			get_inst(env);
	}
	replace_labels(env);
}
