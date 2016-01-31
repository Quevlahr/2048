/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 22:46:13 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/31 22:46:24 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void			rand_tab(int **tab, int nb)
{
	int			rd;
	int			x;
	int			y;
	time_t		t;
	int			ok;

	srand((unsigned)time(&t));
	ok = 1;
	while (ok != 0 && all_empty(tab, nb, 0) == 0)
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
