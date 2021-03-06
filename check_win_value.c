/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 22:39:41 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/31 22:39:43 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int				check_win_value(int nb, int r)
{
	if (nb == 2)
	{
		r = 1;
		return (r);
	}
	if (nb % 2 == 0)
		r = check_win_value(nb / 2, r);
	return (r);
}
