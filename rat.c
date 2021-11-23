/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:00:51 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/23 18:38:51 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		rat(int key, int x, int y, t_vars *vars)
{
	x = 0;
	y = 0;
	if (key == UP_MOUSE)
		vars->zoom += 0.01;
	if (key == DOWN_MOUSE)
		vars->zoom += 0.01;
	vars->change = 1;
	return (0);
}
