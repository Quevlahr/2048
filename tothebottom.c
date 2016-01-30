/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tothebottom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 10:52:18 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/30 10:52:20 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		ft_control(int **tab, int ij, int num)
{
	int			i;
	int			j;

	j = ij % 10;
	ij /= 10;
	i = ij;
	i++;
	while (i >= 0)
	{
		if (tab[i][j] == num)
			return (i);
		else if (tab[i][j] == 0)
			i--;
		else
			return (-1);
	}
	return (-1);
}

static int		ft_bottom(int **tab, int j, int nb, int change)
{
	int			i;
	int			save_i;

	i = nb - 1;
	save_i = -1;
	while (save_i == -1 && i >= 0)
	{
		while (save_i < 0 && i >= 0)
		{
			if (tab[i][j] == 0)
				save_i = i;
			i--;
		}
		while (save_i >= 0 && i >= 0)
		{
			if (tab[i][j] != 0)
			{
				tab[save_i][j] = tab[i][j];
				tab[i][j] = 0;
				i = save_i;
				save_i = -1;
				change = 1;
			}
			else
				i--;
		}
	}
	return (change);
}

int				tothebottom(int **tab, int nb)
{
	int			i;
	int			j;
	int			num;
	int			tmp_i;
	int			ij;
	int			change;

	j = 0;
	change = 0;
	while (j < nb)
	{
		i = nb - 1;
		while (i >= 0)
		{
			ij = i * 10 + j;
			if ((num = tab[i][j]) && (tmp_i = ft_control(tab, ij, num)) != -1)
			{
				tab[tmp_i][j] = 0;
				tab[i][j] = num * 2;
				change += 1;
			}
			i--;
		}
		change += ft_bottom(tab, j, nb, change);
		clear();
		initscr();
		print_tab(tab, nb);
		refresh();
		j++;
	}
	return (change);
}
