/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 20:53:40 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/31 20:53:43 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int				ft_right(int **tab, int nb, int i)
{
	int			j;
	int			change;
	int			num;

	change = 0;
	while (i < nb)
	{
		j = nb - 1;
		while (j >= 0)
		{
			if ((num = tab[i][j]) && ft_control(tab[i], j, num) != -1)
				change += 1;
			j--;
		}
		i++;
	}
	return (change);
}
