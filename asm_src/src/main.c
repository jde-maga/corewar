/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:13:17 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/18 18:13:18 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	t_env *env;

	if (argc == 2)
	{
		init_env(argv[1]);
		env = get_env(NULL);
		parsing_champion(env);
		create_champion(env);
		free_env();
	}
	else
		ft_error(EBDARG);
	return (0);
}
