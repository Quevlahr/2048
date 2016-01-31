/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 12:52:21 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/31 12:52:47 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		vertical(WINDOW *grid, int x, int y)
{
	int i;
	int j;

	i = 1;
	while (i <= 3)
	{
		j = 1;
		while (j < (y - 1))
		{
			mvwprintw(grid, 1 * j, (x / 4) * i, "|");
			j++;
		}
		i++;
	}
}

static void		horizontal(WINDOW *grid, int x, int y)
{
	int i;
	int j;

	i = 1;
	while (i <= 3)
	{
		j = 1;
		while (j < (y - 1))
		{
			mvwprintw(grid, (x / 4) * i, 1 * j, "-");
			j++;
		}
		i++;
	}
}

static void		firsttab(WINDOW *grid, int **tab, int x, int y, int nb)
{
	int i;
	int j;
	char *d;

	i = 0;
	while (i < nb)
	{
		j = 0;
		while (j < nb)
		{
			if (tab[i][j] > 0)
				d = ft_itoa(tab[i][j]);
			else
				d = " ";
			mvwprintw(grid, y / nb / 2 + i * y / nb, x / nb / 2 + c * x / nb, d);
			j++;
		}
		i++;
	}
}

void			print_tab(WINDOW *grid, int **tab, int nb)
{
	// int a;
	int x;
	int y;

	getmaxyx(grid, y, x);
	vertical(grid, x, y);
	horizontal(grid, x, y);
	firsttab(grid, tab, x, y, nb);
	// a = getch();
	// if (a == 258 || a == 259 || a == 260 || a == 261)
	// {
	// 	tab = gamehandler(tab, 4, a);
	// }
}

// int				print_tab(int **tab, int nb)
// {
// 	int			i;
// 	int			j;
// 	int			x;
// 	int			y;
// 	int			cpt;

// 	start_color();
// 	init_pair(0, 1, 0);
// 	init_pair(1, 7, 0);
// 	init_pair(2, 2, 0);
// 	init_pair(3, 3, 0);
// 	init_pair(4, 4, 0);
// 	init_pair(5, 5, 0);
// 	init_pair(6, 6, 0);
// 	getmaxyx(stdscr, y, x);
// 	(void)tab; //
// 	cpt = 0;
// 	if (y < 9)
// 	{
// 		printw("Agrandissez la fenetre");
// 		return (0);
// 	}
// 	j = 0;
// 	while (j < y && j < y - ((y - 1) % nb))
// 	{
// 		i = 0;
// 		while (i < (x - 2) && i < x - (x % nb))
// 		{
// 			if (j % ((y - 1) / nb) == 0 && i % (x / nb) == 0)
// 				cpt++;
// 			if (j % ((y - 1) / nb) == 0)
// 				printw("-");
// 			else if (i % (x / nb) == 0)
// 				printw("|");
// 			else if (j == (y - 1) / nb / 2 && i == x / nb/ 2)
// 				mvprintw("%d, %d", cpt / nb, (cpt - 1) % nb);
// 			else
// 				printw(" ");
// 			i++;
// 		}
// 		printw("|\n");
// 		j++;
// 	}

	// i = 0;
	// while (i < nb)
	// {
	// 	j = 0;
	// 	while (j < nb)
	// 	{
	// 		attron(COLOR_PAIR(2));
	// 		printw("| %5d %5s", tab[i][j], "");
	// 		attron(COLOR_PAIR(1));
	// 		j++;
	// 	}
	// 	printw("|\n\n");
	// 	i++;
	// }
	// printw("\n");
// 	return (0);
// }
