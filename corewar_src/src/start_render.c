/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:31:23 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/09 17:50:46 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	my_init_color(void)
{
	start_color();
	init_pair(255, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_RED);
	init_pair(10, COLOR_BLUE, COLOR_BLACK);
	init_pair(11, COLOR_WHITE, COLOR_BLUE);
	init_pair(12, COLOR_BLUE, COLOR_RED);
	init_pair(13, COLOR_BLUE, COLOR_CYAN);
	init_pair(20, COLOR_GREEN, COLOR_BLACK);
	init_pair(21, COLOR_BLACK, COLOR_GREEN);
	init_pair(22, COLOR_GREEN, COLOR_RED);
	init_pair(23, COLOR_GREEN, COLOR_CYAN);
	init_pair(30, COLOR_YELLOW, COLOR_BLACK);
	init_pair(31, COLOR_BLACK, COLOR_YELLOW);
	init_pair(32, COLOR_YELLOW, COLOR_RED);
	init_pair(33, COLOR_YELLOW, COLOR_CYAN);
	init_pair(40, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(41, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(42, COLOR_MAGENTA, COLOR_RED);
	init_pair(43, COLOR_MAGENTA, COLOR_CYAN);
}

static void	display_champions(t_env *env)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (env->player_list[i])
	{
		mvwprintw(env->w_menu, 13 + j, 1, "CHAMPION %d : %s",
				env->player_list[i]->number, env->player_list[i]->name);
		mvwprintw(env->w_menu, 14 + j, 1, "LIVE CHECKED :");
		i++;
		j += 3;
	}
}

void		init_display(t_env *env)
{
	WINDOW * main1;
	WINDOW * menu;
	initscr();
	cbreak();
	noecho();
	scrollok(stdscr, TRUE);
	my_init_color();
	main1 = subwin(stdscr, 64, 193, 1, 4);
	menu = subwin(stdscr, 66, 55, 1, 204);
	wbkgd(main1, COLOR_PAIR(255));
	wbkgd(menu, COLOR_PAIR(255));
	env->w_main = main1;
	env->w_menu = menu;
	mvwprintw(env->w_menu, 1, 1, "CYCLES                  :\t\tELAPSED CYCLES");
	mvwprintw(env->w_menu, 3, 1, "NEXT LIVE CHECK IN      :\t\tCYCLES");
	mvwprintw(env->w_menu, 5, 1, "CURRENT CYCLE TO DIE    :\t\tCYCLES");
	mvwprintw(env->w_menu, 8, 1, "CURRENT PROCESS NUMBER  :\t\tPROCESSES");
	mvwprintw(env->w_menu, 11, 1, "LIVE CHECKS : ");
	display_champions(env);
}
