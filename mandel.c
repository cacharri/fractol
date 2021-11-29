/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:43:04 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/29 19:38:12 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandel_init(t_you *yu, int x, int y)
{
	yu->vars.realM = 1.5 * (x - WIDTH / 2) / (0.5 * yu->vars.zoom * WIDTH)
		+ yu->vars.movx;
	yu->vars.ymagM = (y - HEIGHT / 2) / (0.5 * yu->vars.zoom * HEIGHT)
		+ yu->vars.movy;
	yu->vars.nreal = 0;
	yu->vars.nymag = 0;
	yu->vars.olreal = 0;
	yu->vars.olymag = 0;
	return (0);
}

static void	mandel_actual(t_you *yu)
{
	yu->vars.olreal = yu->vars.nreal;
	yu->vars.olymag = yu->vars.nymag;
	yu->vars.nreal = yu->vars.olreal * yu->vars.olreal - yu->vars.olymag
		* yu->vars.olymag + yu->vars.realM;
	yu->vars.nymag = 2 * yu->vars.olreal * yu->vars.olymag + yu->vars.ymagM;
}

int	mandel(t_you *yu)
{
	int	m;
	int	x;
	int	y;

	y = 0;
	mlx_do_sync(yu->data.mlx);
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			m = mandel_init(yu, x, y);
			while (m++ < yu->vars.maxiter)
			{
				mandel_actual(yu);
				if ((yu->vars.nreal * yu->vars.nreal + yu->vars.nymag
						* yu->vars.nymag) > 4)
					break ;
			}
			my_mlx_pixel_put(yu, x, y, yu->data.color << m);
		}
	}
	move(yu);
	mlx_put_image_to_window(yu->data.mlx, yu->data.win, yu->data.img, 0, 0);
	return (0);
}
