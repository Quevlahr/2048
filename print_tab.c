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

static void		colonnes(WINDOW *grid, int x, int y, int nb)
{
	int i;
	int j;

	j = 0;
	while (j <= nb)
	{
		i = 0;
		while (i < y && i < y - ((y - 1) % nb))
		{
			mvwprintw(grid, i, ((x - 1) / nb) * j, "#");
			i++;
		}
		j++;
	}
}

static void		lignes(WINDOW *grid, int x, int y, int nb)
{
	int i;
	int j;

	i = 0;
	while (i <= nb)
	{
		j = 0;
		while (j < x && j < x - ((x - 1) % nb))
		{
			mvwprintw(grid, ((y - 1) / nb) * i, j, "=");
			j++;
		}
		i++;
	}
}

static void		ft_puttab(WINDOW *grid, int **tab, int x, int y, int nb)
{
	int i;
	int j;
	char *str;

	i = 0;
	while (i < nb)
	{
		j = 0;
		while (j < nb)
		{
			if (tab[i][j] > 0)
				str = ft_itoa(tab[i][j]);
			else
				str = " ";
			put_color(grid, (y - 1) / nb / 2 + i * (y - 1) / nb,
				(x - 1) / nb / 2 + j * (x - 1) / nb, str);
			j++;
		}
		i++;
	}
}

int				print_tab(WINDOW *grid, int **tab, int nb)
{
	int x;
	int y;

	getmaxyx(grid, y, x);
	if (y < 9 || x < 37)
	{
		printw("Agrandissez la fenetre");
		return (0);
	}
	colonnes(grid, x, y, nb);
	lignes(grid, x, y, nb);
	ft_puttab(grid, tab, x, y, nb);
	return (0);
}


