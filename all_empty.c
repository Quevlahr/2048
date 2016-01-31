/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_empty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 20:38:40 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/31 20:38:46 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int				all_empty(int **tab, int nb, int verif)
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
	if (verif == 1 && (ft_top(tab, nb, 0, 0) || ft_right(tab, nb, 0) ||
		ft_left(tab, nb, 0) || ft_bottom(tab, nb, 0, 0)))
		return (0);
	return (1);
}
