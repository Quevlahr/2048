/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 21:43:01 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/31 21:43:04 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int				put_color(WINDOW *grid, int y, int x, char *str)
{
	start_color();
	init_pair(0, 1, 0);
	init_pair(1, 7, 0);
	init_pair(2, 2, 0);
	init_pair(3, 3, 0);
	init_pair(4, 4, 0);
	init_pair(5, 5, 0);
	init_pair(6, 6, 0);
	if (ft_atoi(str) == 2 || ft_atoi(str) == 4)
	{
			attron(COLOR_PAIR(1));
			mvwprintw(grid, y, x, str);
			// printw("| %5d %5s", tab[i][j], "");
			attron(COLOR_PAIR(1));
	}
	else if (ft_atoi(str) == 8 || ft_atoi(str) == 16)
	{
			attron(COLOR_PAIR(2));
			mvwprintw(grid, y, x, str);
			// printw("| %5d %5s", tab[i][j], "");
			attron(COLOR_PAIR(1));
	}
	else if (ft_atoi(str) == 32|| ft_atoi(str) == 64)
	{
			attron(COLOR_PAIR(3));
			mvwprintw(grid, y, x, str);
			// printw("| %5d %5s", tab[i][j], "");
			attron(COLOR_PAIR(1));
	}
	else if (ft_atoi(str) == 128 || ft_atoi(str) == 256)
	{
			attron(COLOR_PAIR(4));
			mvwprintw(grid, y, x, str);
			// printw("| %5d %5s", tab[i][j], "");
			attron(COLOR_PAIR(1));
	}
	else if (ft_atoi(str) == 512 || ft_atoi(str) == 1024)
	{
			attron(COLOR_PAIR(5));
			mvwprintw(grid, y, x, str);
			// printw("| %5d %5s", tab[i][j], "");
			attron(COLOR_PAIR(1));
	}
	else if (ft_atoi(str) >= 2048 || ft_atoi(str) == 4)
	{
			attron(COLOR_PAIR(6));
			mvwprintw(grid, y, x, str);
			// printw("| %5d %5s", tab[i][j], "");
			attron(COLOR_PAIR(1));
	}
	return (0);
}
