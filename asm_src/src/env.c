/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:13:50 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/18 18:13:51 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char			*check_filename(char *filename)
{
	int		len;
	char	*ret;

	ret = NULL;
	len = ft_strlen(filename) - 1;
	if (filename[len] == 's' && filename[len - 1] == '.')
	{
		ret = ft_strnew(len - 1);
		ft_strncpy(ret, filename, len - 1);
		return (ret);
	}
	else
		ft_error(E_BD_CHP);
	return (ret);
}

static t_header		*init_header(void)
{
	t_header *new;

	if (!(new = malloc(sizeof(t_header))))
		ft_error(EMALLOC);
	ft_bzero(new, sizeof(t_header));
	new->prog_size = 0;
	new->magic = COREWAR_EXEC_MAGIC;
	return (new);
}

void				init_env(char *filename)
{
	t_env *new;

	if (!(new = malloc(sizeof(t_env))))
		ft_error(EMALLOC);
	ft_bzero(new, sizeof(t_env));
	new->header = init_header();
	new->filename = check_filename(filename);
	new->line_nb = 0;
	new->c_adress = 0;
	new->add_to_adress = 0;
	if ((new->fd = open(filename, O_RDONLY)) < 0)
		ft_error(EOPEN);
	get_env(new);
}

t_env				*get_env(t_env *env)
{
	static t_env *save = NULL;

	if (env == NULL)
		return (save);
	else
	{
		save = env;
		return (save);
	}
}

void				free_env(void)
{
	t_env *env;

	env = get_env(NULL);
	if (env)
	{
		if (env->header)
			free(env->header);
		if (env->filename)
			free(env->filename);
		if (env->line)
			free(env->line);
		free(env);
	}
}
