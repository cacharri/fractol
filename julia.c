/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:23:52 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/29 19:38:10 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int	julia_init(t_you *yu, int x, int y)
{
	yu->vars.nreal = 1.5 * (x - WIDTH / 2) / (0.5 * yu->vars.zoom * WIDTH)
		+ yu->vars.movx;
	yu->vars.nymag = (y - HEIGHT / 2) / (0.5 * yu->vars.zoom * HEIGHT)
		+ yu->vars.movy;
	return (0);
}

static	void	julia_actual(t_you *yu)
{
	yu->vars.olreal = yu->vars.nreal;
	yu->vars.olymag = yu->vars.nymag;
	yu->vars.nreal = yu->vars.olreal * yu->vars.olreal - yu->vars.olymag
		* yu->vars.olymag + yu->vars.real;
	yu->vars.nymag = 2 * yu->vars.olreal * yu->vars.olymag + yu->vars.ymag;
}

int	julia(t_you *yu)
{
	int	j;
	int	x;
	int	y;

	y = 0;
	mlx_do_sync(yu->data.mlx);
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			j = julia_init(yu, x, y);
			while (j++ < yu->vars.maxiter)
			{
				julia_actual(yu);
				if ((yu->vars.nreal * yu->vars.nreal + yu->vars.nymag
						* yu->vars.nymag) > 4)
					break ;
			}
			my_mlx_pixel_put(yu, x, y, yu->data.color << j);
		}
	}
	move(yu);
	mlx_put_image_to_window(yu->data.mlx, yu->data.win, yu->data.img, 0, 0);
	return (0);
}
