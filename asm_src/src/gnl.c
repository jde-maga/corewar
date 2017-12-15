/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:13:58 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/20 22:11:32 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	remove_comment(t_env *env)
{
	int i;

	i = 0;
	while (env->line[i])
	{
		if (env->line[i] == '"')
		{
			i++;
			while (env->line[i] && env->line[i] != '"')
				i++;
			if (!env->line[i])
				return ;
		}
		if (env->line[i] == COMMENT_CHAR || env->line[i] == ';')
		{
			env->line = ft_strget_f(env->line, 0, i);
			return ;
		}
		i++;
	}
}

int		check_empty_line(char *line)
{
	int i;

	i = 0;
	if (line)
	{
		while (line[i])
		{
			if (line[i] != ' ' && line[i] != '	')
				return (0);
			i++;
		}
	}
	return (1);
}

int		gnl(void)
{
	int				ret;
	int				loop;
	t_env			*env;

	loop = 1;
	ret = 1;
	env = get_env(NULL);
	while (loop == 1 && ret > 0)
	{
		env->line_nb++;
		if ((ret = get_next_line(env->fd, &(env->line))) < 0)
			ft_error(EGNL);
		if (ret == 1)
			remove_comment(env);
		loop = check_empty_line(env->line);
	}
	env->line = ft_strtrim_f(env->line);
	return (ret);
}
