/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:30:31 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/29 16:45:55 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	touch(int keydo, t_you *yu)
{
	if (keydo == 53)
	{
		mlx_clear_window(yu->data.mlx, yu->data.win);
		mlx_destroy_window(yu->data.mlx, yu->data.win);
		exit(0);
	}
	if (keydo == 13 && yu->data.w == 0)
		yu->data.w = 1;
	if (keydo == 1 && yu->data.s == 0)
		yu->data.s = 1;
	if (keydo == 2 && yu->data.d == 0)
		yu->data.d = 1;
	if (keydo == 0 && yu->data.a == 0)
		yu->data.a = 1;
	return (0);
}

int	move(t_you *yu)
{
	if (yu->data.w == 1)
		yu->vars.ymag += 0.0004;
	if (yu->data.s == 1)
		yu->vars.ymag -= 0.0004;
	if (yu->data.d == 1)
		yu->vars.real += 0.0004;
	if (yu->data.a == 1)
		yu->vars.real -= 0.0004;
	return (0);
}

int	free_touch(int keydo, t_you *yu)
{

	if (keydo == 13 && yu->data.w == 1)
		yu->data.w = 0;
	if (keydo == 1 && yu->data.s == 1)
		yu->data.s = 0;
	if (keydo == 2 && yu->data.d == 1)
		yu->data.d = 0;
	if (keydo == 0 && yu->data.a == 1)
		yu->data.a = 0;
	return (0);
}
