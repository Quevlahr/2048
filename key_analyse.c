/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_analyse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 22:41:44 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/31 22:41:46 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		key_move(int **tab, int nb, int key)
{
	if (key == KEY_LEFT)
	{
		if (totheleft(tab, nb, 0) != 0)
			rand_tab(tab, nb);
	}
	else if (key == KEY_RIGHT)
	{
		if (totheright(tab, nb, 0) != 0)
			rand_tab(tab, nb);
	}
	else if (key == KEY_UP)
	{
		if (tothetop(tab, nb, 0, 0) != 0)
			rand_tab(tab, nb);
	}
	else if (key == KEY_DOWN)
	{
		if (tothebottom(tab, nb, 0, 0) != 0)
			rand_tab(tab, nb);
	}
	return (1);
}

static int		win_or_not(int **tab, int nb, int *win)
{
	int			i;
	int			j;

	i = 0;
	while (i < nb)
	{
		j = 0;
		while (j < nb)
		{
			if (tab[i][j] == WIN_VALUE)
			{
				*win = 1;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int		key_escape(int **tab, int nb, int key)
{
	int			x;
	int			y;

	getmaxyx(stdscr, y, x);
	if (key == ESCAPE)
	{
		free(tab);
		endwin();
		return (0);
	}
	else if (all_empty(tab, nb, 1) != 0)
	{
		clear();
		mvprintw(y / 2, x / 2 - 4, "You lose... :(.");
		mvprintw((y / 2) + 1, x / 2 - 4, "Press a key to leave");
		getch();
		refresh();
		free(tab);
		endwin();
		return (0);
	}
	return (1);
}

int				key_analyse(int **tab, int nb, int key, int *win)
{
	int			x;
	int			y;

	getmaxyx(stdscr, y, x);
	if (key_escape(tab, nb, key) == 0)
		return (0);
	key_move(tab, nb, key);
	if (*win == 0 && win_or_not(tab, nb, win) == 1)
	{
		clear();
		mvprintw(y / 2, x / 2 - 4, "You win :D");
		mvprintw((y / 2) + 1, x / 2 - 4, "Press a key to continue");
		getch();
		refresh();
	}
	return (1);
}
