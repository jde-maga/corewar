/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:12:02 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/18 18:12:05 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	**init_args(void)
{
	char	**args;
	int		i;

	args = malloc(sizeof(char*) * 4);
	i = 0;
	while (i < 4)
		args[i++] = NULL;
	return (args);
}

int		handle_overflow(char *tmp)
{
	if (ft_strlen(tmp) > 19)
	{
		if (tmp[0] == '-')
			return (0);
		else
			return (-1);
	}
	else
		return (1);
}

char	*get_reg(char *arg)
{
	t_env	*env;
	int		i;
	char	*tmp;

	tmp = ft_strnew(3);
	env = get_env(NULL);
	env->add_to_adress++;
	i = 1;
	while (arg[i])
	{
		tmp[i - 1] = arg[i];
		i++;
	}
	return (convert_hex_octnb(ft_atoi(tmp), 1));
}

char	*get_dir(char *arg, int size)
{
	t_env		*env;
	int			i;
	char		*tmp;
	long int	tmp_value;

	tmp = ft_strnew(ft_strlen(arg));
	env = get_env(NULL);
	env->add_to_adress += size;
	if (arg[1] == LABEL_CHAR)
	{
		arg[0] = LABEL_CHAR;
		arg[1] = DIRECT_CHAR;
		return (ft_strjoin(ft_strjoin(arg, ft_itoa(size)), ":"));
	}
	else
	{
		i = 0;
		while (arg[++i])
			tmp[i - 1] = arg[i];
		tmp_value = handle_overflow(tmp);
		if (tmp_value == 1)
			tmp_value = ft_atoi(tmp);
		return (convert_hex_octnb(tmp_value, size));
	}
}

char	*get_ind(char *arg)
{
	t_env	*env;
	int		i;
	char	*tmp;
	int		tmp_value;

	tmp = ft_strnew(ft_strlen(arg));
	env = get_env(NULL);
	env->add_to_adress += 2;
	if (arg[0] == LABEL_CHAR)
		return (ft_strjoin(arg, ":"));
	else
	{
		i = -1;
		while (arg[++i])
			tmp[i] = arg[i];
		tmp_value = handle_overflow(tmp);
		if (tmp_value == 1)
			tmp_value = ft_atoi_short(tmp);
		return (convert_hex_octnb(tmp_value, 2));
	}
}
