/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubard <jaubard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 21:29:38 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/31 11:16:05 by jaubard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pour compiler gcc -Wall -Wextra -Werror *.c -L libft -lft -lncurses
// http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/helloworld.html pour ncurses
// On peut utiliser la fonction signal pour detecter un window resize.

#include "game.h"

static void		vertical(WINDOW *grid, int x, int y)
{
	int a;
	int b;

	a = 1;
	while (a <= 3)
	{
		b = 1;
		while (b < (x - 1))
		{
			mvwprintw(grid, 1 * b, (y / 4) * a, "|");
			b++;
		}
		a++;
	}
}

static void		horizontal(WINDOW *grid, int x, int y)
{
	int a;
	int b;

	a = 1;
	while (a <= 3)
	{
		b = 1;
		while (b < (y - 1))
		{
			mvwprintw(grid, (x / 4) * a, 1 * b, "-");
			b++;
		}
		a++;
	}
}

static void firsttab(WINDOW *grid, int **tab, int x, int y, int b)
{
	int a;
	int c;
	char *d;

	a = 0;
	while (a < b)
	{
		c = 0;
		while (c < b)
		{
			if (tab[a][c] > 0)
				d = ft_itoa(tab[a][c]);
			else
				d = " ";
			mvwprintw(grid, x / b / 2 + a * x / b, y / b / 2 + c * y / b, d);
			c++;
		}
		a++;
	}
}

static void	print(WINDOW *grid, int **tab, int b)
{
	// int a;
	int x;
	int y;

	getmaxyx(grid, x, y);
	vertical(grid, x, y);
	horizontal(grid, x, y);
	firsttab(grid, tab, x, y, b);
	// a = getch();
	// if (a == 258 || a == 259 || a == 260 || a == 261)
	// {
	// 	tab = gamehandler(tab, 4, a);
	// }
}

static int		**create_tab(int **tab, int nb)
{
	int			i;
	int			j;

	i = 0;
	if (!(tab = (int**)malloc(sizeof(int*) * nb)))
		return (NULL);
	while (i < nb)
	{
		j = 0;
		if (!(tab[i] = (int*)malloc(sizeof(int) * nb)))
			return (NULL);
		while (j < nb)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

static int		all_empty(int **tab, int nb)
{
	int			i;
	int			j;

	i = 0;
	while (i < nb)
	{
		j = 0;
		while (j < nb)
		{
			if (tab[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void		rand_tab(int **tab, int nb)
{
	int			rd;
	int			x;
	int			y;
	time_t		t;
	int			ok;

	srand((unsigned)time(&t));
	ok = 1;
	while (ok != 0 && all_empty(tab, nb) == 0)
	{
		x = rand() % nb;
		y = rand() % nb;
		if (rand() % 2 == 0)
			rd = 2;
		else
			rd = 4;
		if (tab[x][y] == 0)
		{
			tab[x][y] = rd;
			ok = 0;
		}
	}
}

int				main(void)
{
	int			**tab;
	int			key;
	int			x;
	int			y;
	int			nb;
	WINDOW		*grid; //

	nb = 4;
	key = 0;
	tab = NULL;
	tab = create_tab(tab, nb);
	rand_tab(tab, nb);
	rand_tab(tab, nb);
	initscr();
	while (1)
	{
		clear();
		raw();
		noecho();
		keypad(stdscr, TRUE);
		getmaxyx(stdscr, y, x);
		grid = subwin(stdscr, y, x, 0, 0);
		// print_tab(tab, nb);
		print(grid, tab, nb);
		// mvprintw(y / 2, x / 2, "|  x = %d, y = %d  |", x, y);
		key = getch();
		refresh();
		if (key == ESCAPE)
		{
			endwin();
			return (0);
		}
		// else if (all_empty(tab, nb) != 0)
		// {
		// 	clear();
		// 	initscr();
		// 	print_tab(tab, nb);
		// 	mvprintw(y / 2, x / 2 - 4, "Tu as perdu... :(.");
		// 	refresh();
		// 	sleep(2);
		// 	endwin();
		// 	return (0);
		// }
		else if (key == KEY_LEFT)
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
	}
	return (0);
}
