/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 20:53:23 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/31 20:53:25 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_control(int **tab, int ij, int num, int nb)
{
	int			i;
	int			j;

	j = ij % 10;
	ij /= 10;
	i = ij;
	i++;
	while (i < nb)
	{
		if (tab[i][j] == num)
			return (i);
		else if (tab[i][j] == 0)
			i++;
		else
			return (-1);
	}
	return (-1);
}

int				ft_top(int **tab, int nb, int ij, int j)
{
	int			i;
	int			num;
	int			change;

	change = 0;
	while (j < nb)
	{
		i = 0;
		while (i < nb && (ij = i * 10 + j) != -1)
		{
			if ((num = tab[i][j]) && ft_control(tab, ij, num, nb) != -1)
				change += 1;
			i++;
		}
		j++;
	}
	return (change);
}
