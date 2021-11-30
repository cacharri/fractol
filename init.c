/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:47:58 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/30 18:23:57 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init(t_you *yu)
{
	ft_bzero(&yu->vars, sizeof(yu->vars));
	ft_bzero(&yu->data, sizeof(yu->data));
	yu->vars.maxiter = 300;
	yu->vars.real = -0.7;
	yu->vars.ymag = 0.27015;
	yu->vars.zoom = 1;
	yu->vars.movxM = -0.5;
	yu->data.color = colorme(132, 28, 192);
	yu->vars.mxitexp = 128;
	return (0);
}

void	my_mlx_pixel_put(t_you *yu, int x, int y, int color)
{
	char	*dst;

	dst = yu->data.addr + (y * yu->data.line_lenght + x
			* (yu->data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
