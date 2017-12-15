/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:42:28 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/20 21:08:14 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	get_dump(int ac, char **av)
{
	int dump_value;

	if (ac < 3)
		return (-1);
	if (!ft_isint(av[2]))
		return (-1);
	dump_value = ft_atoi(av[2]);
	if (dump_value < 0)
		return (-1);
	return (dump_value);
}

static int	dump_arg_check(int *i, int ac, char **av, t_env *env)
{
	if (!ft_strcmp("-dump", av[1]) && DISPLAY)
		return (0);
	if (ac >= 3 && !ft_strcmp("-dump", av[1]))
	{
		if ((env->dump = get_dump(ac, av)) == -1)
			return (0);
		*i += 2;
	}
	return (1);
}

static int	n_arg_check(int *i, int *k, int ac, char **av)
{
	if (!ft_strcmp("-n", av[*i]))
	{
		if (*i + 2 < ac && ft_isint(av[*i + 1]) && ft_atoi(av[*i + 1]) > 0)
			*k = ft_atoi(av[*i + 1]);
		else
			return (0);
		*i += 2;
	}
	return (1);
}

static int	playerlist_parser(t_env *env, int *j, int fd, int *k)
{
	static int l;

	if (!l)
		l = -1;
	if (env->arena->player_amount + 1 > MAX_PLAYERS)
		return (0);
	env->player_list[*j] = file_parser(fd, env);
	env->arena->player_amount++;
	if (*k)
		env->player_list[*j]->number = *k;
	else
	{
		env->player_list[*j]->number = l;
		l--;
	}
	*k = 0;
	env->player_list[*j + 1] = NULL;
	(*j)++;
	return (1);
}

int			arg_parser(int ac, char **av, t_env *env)
{
	int i;
	int fd;
	int j;
	int k;

	i = 1;
	j = 0;
	k = 0;
	if (!dump_arg_check(&i, ac, av, env))
		return (-1);
	while (i != ac)
	{
		if (!n_arg_check(&i, &k, ac, av))
			return (-2);
		if ((fd = open(av[i], O_RDONLY)) != -1)
		{
			if (!playerlist_parser(env, &j, fd, &k))
				return (-4);
		}
		else
			return (-3);
		i++;
	}
	return (1);
}
