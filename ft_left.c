/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 20:53:49 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/31 20:53:51 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_control(int *tab, int j, int num, int nb)
{
	j++;
	while (j < nb)
	{
		if (tab[j] == num)
			return (j);
		else if (tab[j] == 0)
			j++;
		else
			return (-1);
	}
	return (-1);
}

int				ft_left(int **tab, int nb, int i)
{
	int			j;
	int			change;
	int			num;

	change = 0;
	while (i < nb)
	{
		j = 0;
		while (j < nb)
		{
			if ((num = tab[i][j]) && ft_control(tab[i], j, num, nb) != -1)
				change += 1;
			j++;
		}
		i++;
	}
	return (change);
}
