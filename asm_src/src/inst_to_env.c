/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_to_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:13:02 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/18 18:13:03 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	char	*get_full_inst(char *inst, char *args_code, char **args)
{
	int		i;
	char	*full_inst;

	i = 0;
	full_inst = args[i];
	while (args[i + 1])
	{
		full_inst = ft_strjoin(full_inst, args[i + 1]);
		i++;
	}
	if (args_code)
		full_inst = ft_strjoin(ft_strjoin(inst, args_code), full_inst);
	else
		full_inst = ft_strjoin(inst, full_inst);
	return (full_inst);
}

static	t_inst	*new_inst(t_env *env, char *inst)
{
	t_inst *new;

	new = malloc(sizeof(t_inst));
	new->content = inst;
	new->adress = env->c_adress;
	new->line = env->line_nb;
	new->next = NULL;
	return (new);
}

static	void	add_inst_to_env(t_env *env, char *inst)
{
	t_inst	*new;
	t_inst	*tmp;

	new = new_inst(env, inst);
	if (!(env->inst))
		env->inst = new;
	else
	{
		tmp = env->inst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void			inst_to_env(char *inst, char *args_code, char **args)
{
	t_env	*env;
	char	*full_inst;

	env = get_env(NULL);
	if (args_code)
		env->add_to_adress += 2;
	else
		env->add_to_adress++;
	full_inst = get_full_inst(inst, args_code, args);
	add_inst_to_env(env, full_inst);
	env->c_adress += env->add_to_adress;
	env->add_to_adress = 0;
}
