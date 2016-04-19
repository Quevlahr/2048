/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubard <jaubard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 21:30:58 by quroulon          #+#    #+#             */
/*   Updated: 2016/04/19 12:45:18 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "libft/libft.h"
# include <ncurses.h>
# include <time.h>

# define ESCAPE 27

enum			e_const
{
	WIN_VALUE = 2048
};

int				totheleft(int **tab, int nb, int i);
int				totheright(int **tab, int nb, int i);
int				tothetop(int **tab, int nb, int ij, int j);
int				tothebottom(int **tab, int nb, int ij, int j);
int				print_tab(WINDOW *grid, int **tab, int nb);
int				all_empty(int **tab, int nb, int verif);
int				ft_top(int **tab, int nb, int ij, int j);
int				ft_left(int **tab, int nb, int i);
int				ft_bottom(int **tab, int nb, int ij, int j);
int				ft_right(int **tab, int nb, int i);
int				put_color(WINDOW *grid, int y, int x, char *str);
int				check_win_value(int nb, int r);
int				key_analyse(int **tab, int nb, int key, int *win);
void			rand_tab(int **tab, int nb);

#endif
