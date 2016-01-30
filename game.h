/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 21:30:58 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/29 21:32:23 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "libft/includes/libft.h"
# include <ncurses.h>
# include <time.h>

# define WIN_VALUE 2048
# define ESCAPE 27

int				main(void);
int				totheleft(int **tab, int nb);
int				totheright(int **tab, int nb);
int				tothetop(int **tab, int nb);
int				tothebottom(int **tab, int nb);
int				print_tab(int **tab, int nb);

#endif
