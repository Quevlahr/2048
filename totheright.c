/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totheright.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 06:14:34 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/30 06:14:37 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		ft_control(int *tab, int j, int num)
{
	j--;
	while (j >= 0)
	{
		if (tab[j] == num)
			return (j);
		else if (tab[j] == 0)
			j--;
		else
			return (-1);
	}
	return (-1);
}

static int		ft_helper(int *tab, int *j, int *save_j)
{
	tab[*save_j] = tab[*j];
	tab[*j] = 0;
	*j = *save_j;
	*save_j = -1;
	return (1);
}

static void		ft_printcurse(int **tab, int nb)
{
	clear();
	initscr();
	print_tab(tab, nb);
	refresh();
}

static int		ft_right(int *tab, int nb, int change)
{
	int			j;
	int			save_j;

	j = nb - 1;
	save_j = -1;
	while (save_j == -1 && j >= 0)
	{
		while (save_j < 0 && j >= 0)
		{
			if (tab[j] == 0)
				save_j = j;
			j--;
		}
		while (save_j >= 0 && j >= 0)
		{
			if (tab[j] != 0)
				change = ft_helper(tab, &j, &save_j);
			else
				j--;
		}
	}
	return (change);
}

int				totheright(int **tab, int nb, int i)
{
	int			j;
	int			change;
	int			tmp_j;
	int			num;

	change = 0;
	while (i < nb)
	{
		j = nb - 1;
		while (j >= 0)
		{
			if ((num = tab[i][j]) && ft_control(tab[i], j, num) != -1)
			{
				tmp_j = ft_control(tab[i], j, num);
				tab[i][tmp_j] = 0;
				tab[i][j] = num * 2;
				change += 1;
			}
			j--;
		}
		change += ft_right(tab[i], nb, change);
		ft_printcurse(tab, nb);
		i++;
	}
	return (change);
}
