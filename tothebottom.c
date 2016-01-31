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
	i--;
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

static int		ft_helper(int **tab, int *i, int j, int *save_i)
{
	tab[*save_i][j] = tab[*i][j];
	tab[*i][j] = 0;
	*i = *save_i;
	*save_i = -1;
	return (1);
}

static int		ft_movebottom(int **tab, int j, int nb, int change)
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
				change = ft_helper(tab, &i, j, &save_i);
			else
				i--;
		}
	}
	return (change);
}

int				tothebottom(int **tab, int nb, int ij, int j)
{
	int			i;
	int			num;
	int			tmp_i;
	int			change;

	change = 0;
	while (j < nb)
	{
		i = nb - 1;
		while (i >= 0 && (ij = i * 10 + j) != -1)
		{
			if ((num = tab[i][j]) != 0 && ft_control(tab, ij, num) != -1)
			{
				tmp_i = ft_control(tab, ij, num);
				tab[tmp_i][j] = 0;
				tab[i][j] = num * 2;
				change += 1;
			}
			i--;
		}
		change += ft_movebottom(tab, j, nb, change);
		j++;
	}
	return (change);
}
