/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 21:43:01 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/31 21:43:04 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		color1(WINDOW *grid, int y, int x, char *str)
{
	if (ft_atoi(str) == 2 || ft_atoi(str) == 4)
	{
		wattron(grid, COLOR_PAIR(6));
		mvwprintw(grid, y, x, str);
		wattron(grid, COLOR_PAIR(1));
	}
	else if (ft_atoi(str) == 8 || ft_atoi(str) == 16)
	{
		wattron(grid, COLOR_PAIR(2));
		mvwprintw(grid, y, x, str);
		wattron(grid, COLOR_PAIR(1));
	}
}

static void		color2(WINDOW *grid, int y, int x, char *str)
{
	if (ft_atoi(str) == 32 || ft_atoi(str) == 64 || ft_atoi(str) == 128)
	{
		wattron(grid, COLOR_PAIR(4));
		mvwprintw(grid, y, x, str);
		wattron(grid, COLOR_PAIR(1));
	}
	else if (ft_atoi(str) == 256 || ft_atoi(str) == 512)
	{
		wattron(grid, COLOR_PAIR(5));
		mvwprintw(grid, y, x, str);
		wattron(grid, COLOR_PAIR(1));
	}
	else if (ft_atoi(str) == 1024 || ft_atoi(str) == 2048)
	{
		wattron(grid, COLOR_PAIR(1));
		mvwprintw(grid, y, x, str);
		wattron(grid, COLOR_PAIR(1));
	}
}

int				put_color(WINDOW *grid, int y, int x, char *str)
{
	start_color();
	init_pair(1, 2, 0);
	init_pair(2, 3, 0);
	init_pair(4, 5, 0);
	init_pair(5, 6, 0);
	init_pair(6, 7, 0);
	if (ft_atoi(str) >= 2 && ft_atoi(str) <= 16)
		color1(grid, y, x, str);
	else if (ft_atoi(str) >= 32 && ft_atoi(str) <= 2048)
		color2(grid, y, x, str);
	else
	{
		wattron(grid, COLOR_PAIR(6));
		mvwprintw(grid, y, x, str);
		wattron(grid, COLOR_PAIR(1));
	}
	return (0);
}
