/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:13:08 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/18 18:13:09 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			add_label(t_env *env, char *label)
{
	t_label	*new_label;
	t_label	*tmp;

	new_label = malloc(sizeof(t_label));
	new_label->next = NULL;
	new_label->name = ft_strnew(ft_strlen(label));
	ft_strcpy(new_label->name, label);
	new_label->adress = env->c_adress;
	if (!env->labels)
		env->labels = new_label;
	else
	{
		tmp = env->labels;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_label;
	}
}

char			*get_label_inst(t_label *label, t_env *env)
{
	t_inst	*inst;
	char	*content;

	inst = env->inst;
	while (inst->adress != label->adress)
		inst = inst->next;
	content = ft_strnew(4);
	ft_strncpy(content, inst->content, 4);
	return (content);
}

static	char	*replace_label(char *label_name, int adress, t_env *env)
{
	int		dir;
	t_label	*tmp;

	dir = 0;
	if (label_name[0] == DIRECT_CHAR)
	{
		dir = ft_atoi(&(label_name[ft_strlen(label_name) - 1]));
		label_name = ft_strcut_beg(ft_strcut_end(label_name, 1), 1);
	}
	if (!(tmp = env->labels))
		ft_error(E_UK_LBL);
	while (ft_strcmp(tmp->name, label_name) != 0)
	{
		if (!tmp->next)
			ft_error(E_UK_LBL);
		tmp = tmp->next;
	}
	free(label_name);
	if (dir)
		return (convert_hex_octnb(tmp->adress - adress, dir));
	else
		return (convert_hex_octnb(tmp->adress - adress, 2));
}

void			replace_labels(t_env *env)
{
	t_inst	*tmp;
	char	**split;
	int		loop;

	loop = 0;
	tmp = env->inst;
	while (tmp)
	{
		split = ft_strsplit(tmp->content, LABEL_CHAR);
		if (split[1] && (split[1][0] == DIRECT_CHAR || loop))
		{
			split[1] = replace_label(split[1], tmp->adress, env);
			tmp->content = ft_tab_join(split);
		}
		else
			tmp = tmp->next;
		if (!tmp && loop == 0)
		{
			tmp = env->inst;
			loop++;
		}
		ft_tab_free(split);
	}
}
