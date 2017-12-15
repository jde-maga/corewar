/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:14:49 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/18 18:14:50 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_name_comment(t_env *env)
{
	ft_putstr("\nchampion's name: ");
	ft_putstr(env->header->prog_name);
	ft_putstr("\nchampion's comment: ");
	ft_putstr(env->header->comment);
}

void	print_add_inst(char *inst, char *args_code, char **args)
{
	int i;

	i = 0;
	ft_putstr("\ninst: ");
	ft_putstr(inst);
	if (args_code)
	{
		ft_putstr("\nargs_code: ");
		ft_putstr(args_code);
	}
	ft_putstr("\nargs:");
	while (args[i])
	{
		ft_putstr(" ");
		ft_putstr(args[i]);
		i++;
	}
}

void	print_labels(t_env *env)
{
	t_label *tmp;

	ft_putstr("\nLABEL_LST: ");
	if (!env->labels)
		return ;
	tmp = env->labels;
	while (tmp->next)
	{
		ft_putstr(tmp->name);
		ft_putstr("(");
		ft_putstr(ft_itoa(tmp->adress));
		ft_putstr(")/");
		tmp = tmp->next;
	}
	ft_putstr(tmp->name);
	ft_putstr("(");
	ft_putstr(ft_itoa(tmp->adress));
	ft_putstr(")\n");
}

void	print_inst(t_env *env)
{
	t_inst *tmp;

	ft_putstr("\n\nINSTRUCTIONS:\n");
	tmp = env->inst;
	while (tmp->next)
	{
		ft_putstr(tmp->content);
		ft_putstr("\n");
		tmp = tmp->next;
	}
	ft_putstr(tmp->content);
	ft_putstr("\n");
}

void	print_champ(char **tab, char *final)
{
	ft_putstr("\nMAGIC:");
	ft_putstr(tab[0]);
	ft_putstr("\nNAME:");
	ft_putstr(tab[1]);
	ft_putstr("\nNAME LEN:");
	ft_putstr(ft_itoa(ft_strlen(tab[1]) / 2));
	ft_putstr("\nSIZE:");
	ft_putstr(tab[2]);
	ft_putstr("\nCOMMENT:");
	ft_putstr(tab[3]);
	ft_putstr("\nCOMMENT LEN:");
	ft_putstr(ft_itoa(ft_strlen(tab[3]) / 2));
	ft_putstr("\nINSTS:");
	ft_putstr(tab[4]);
	if (final)
	{
		ft_putstr("\nFINAL:\n");
		ft_putstr(final);
	}
}
