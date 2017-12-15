/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:11:36 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/18 18:11:40 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	int		check_reg(char *arg)
{
	int		i;
	char	*tmp;
	int		nb;

	i = 1;
	tmp = ft_strnew(10);
	while (arg[i])
	{
		tmp[i - 1] = arg[i];
		if (i > 2 || !ft_isdigit(arg[i++]))
			ft_error(E_BD_REG);
	}
	nb = ft_atoi(tmp);
	if (nb < 0 || nb > 99)
		ft_error(E_BD_REG);
	return (1);
}

static	int		check_dir(char *arg)
{
	int		i;
	char	*tmp;

	tmp = ft_strnew(ft_strlen(arg));
	if (arg[1] != LABEL_CHAR)
	{
		i = 1;
		while (arg[i])
		{
			tmp[i - 1] = arg[i];
			if ((!ft_isdigit(arg[i]) && arg[i] != '-'))
				ft_error(E_BD_DIR);
			i++;
		}
	}
	return (2);
}

static	int		check_ind(char *arg)
{
	int		i;
	char	*tmp;

	tmp = ft_strnew(ft_strlen(arg));
	if (arg[0] != LABEL_CHAR)
	{
		i = 0;
		while (arg[i] && arg[i] != ' ' && arg[i] != SEPARATOR_CHAR)
		{
			tmp[i] = arg[i];
			if ((!ft_isdigit(arg[i]) && arg[i] != '-'))
				ft_error(E_BD_IND);
			i++;
		}
	}
	return (3);
}

int				check_arg(char *arg)
{
	if (arg[0] == 'r' && check_reg(arg))
		return (1);
	else if (arg[0] == DIRECT_CHAR && check_dir(arg))
		return (2);
	else
	{
		check_ind(arg);
		return (3);
	}
}
