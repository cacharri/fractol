/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:30:31 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/17 18:39:04 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	touch(int keydo, t_data *dat)
{
	if (keydo == 53)
	{
		mlx_clear_window(dat->mlx, dat->win);
		mlx_destroy_window(dat->mlx, dat->win);
		exit(0);
	}
	if (keydo == 13 && dat->w == 0)
		dat->w = 1;
	if (keydo == 1 && dat->s == 0)
		dat->s = 1;
	if (keydo == 2 && dat->d == 0)
		dat->d = 1;
	if (keydo == 0 && dat->a == 0)
		dat->a = 1;
	return (0);
}

int	move(t_data *dat, t_vars *var)
{
	if (dat->w == 1)
		var->ymag += 0.0003;
	if (dat->s == 1)
		var->ymag -= 0.0003;
	if (dat->d == 1)
		var->real += 0.0003;
	if (dat->a == 1)
		var->real -= 0.0003;
	return (0);
}

int	free_touch(int keydo, t_data *dat)
{

	if (keydo == 13 && dat->w == 1)
		dat->w = 0;
	if (keydo == 1 && dat->s == 1)
		dat->s = 0;
	if (keydo == 2 && dat->d == 1)
		dat->d = 0;
	if (keydo == 0 && dat->a == 1)
		dat->a = 0;
	return (0);
}
int	exit_touch(t_data *dat)
{
	mlx_destroy_window(dat->mlx, dat->win);
	exit (0);
}
