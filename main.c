/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 21:29:38 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/29 21:29:42 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		**create_tab(int **tab, int nb)
{
	int			i;
	int			j;

	i = 0;
	tab = (int**)malloc(sizeof(int*) * nb);
	while (i < nb)
	{
		j = 0;
		tab[i] = (int*)malloc(sizeof(int) * nb);
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

	srand((unsigned) time(&t));
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

int				print_tab(int **tab, int nb)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < nb)
	{
		j = 0;
		while (j < nb)
		{
			printw("| %d ", tab[i][j]);
			j++;
		}
		printw("|\n");
		i++;
	}
	printw("\n");
	return (0);
}

int				main(void)
{
	int			**tab;
	int			key;
	int			x, y;
	int			nb = 4;

	key = 0;
	tab = NULL;
	tab = create_tab(tab, nb);
	rand_tab(tab, nb);
	rand_tab(tab, nb);
	while (1)
	{
		clear();
		initscr();
		raw();
		noecho();
		keypad(stdscr, TRUE);
		getmaxyx(stdscr, y, x);
		print_tab(tab, nb);
		mvprintw(y/2, x/2, "The key pressed is %d.", key);
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
		// 	print_tab(tab,nb);
		// 	mvprintw(y/2, x/2 - 4, "T'as ptete perdu...!");	
		// 	refresh();
		// 	sleep(2);
		// }
		else if (key == KEY_LEFT)
		{
			if (totheleft(tab, nb) != 0)
				rand_tab(tab, nb);
		}
		else if (key == KEY_RIGHT)
		{
			if (totheright(tab, nb) != 0)
				rand_tab(tab, nb);
		}
		else if (key == KEY_UP)
		{
			if (tothetop(tab, nb) != 0)
				rand_tab(tab, )
		}
	}
	return (0);
}
