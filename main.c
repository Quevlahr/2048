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

#include "game.h"

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

static int		initncurses(int **tab, int nb, int x, int y)
{
	int			key;
	WINDOW		*grid;

	initscr();
	while (1)
	{
		clear();
		raw();
		noecho();
		keypad(stdscr, TRUE);
		getmaxyx(stdscr, y, x);
		grid = subwin(stdscr, y, x, 0, 0);
		print_tab(grid, tab, nb);
		key = getch();
		refresh();
		if (key_analyse(tab, nb, key) == 0)
			return (0);
	}
}

int				main(int ac, char **av)
{
	int			**tab;
	int			nb;

	if (check_win_value(WIN_VALUE, 0) == 0)
	{
		ft_putendl("WIN_VALUE is not valid");
		return (1);
	}
	nb = 4;
	if (ac == 2 && (ft_atoi(av[1]) == 4 || ft_atoi(av[1]) == 5))
		nb = ft_atoi(av[1]);
	tab = NULL;
	tab = create_tab(tab, nb);
	rand_tab(tab, nb);
	rand_tab(tab, nb);
	initncurses(tab, nb, 0, 0);
	return (0);
}
