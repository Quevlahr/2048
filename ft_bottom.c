/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bottom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 20:53:32 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/31 20:53:33 by quroulon         ###   ########.fr       */
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

int				ft_bottom(int **tab, int nb, int ij, int j)
{
	int			i;
	int			num;
	int			change;

	change = 0;
	while (j < nb)
	{
		i = nb - 1;
		while (i >= 0 && (ij = i * 10 + j) != -1)
		{
			if ((num = tab[i][j]) != 0 && ft_control(tab, ij, num) != -1)
				change += 1;
			i--;
		}
		j++;
	}
	return (change);
}
