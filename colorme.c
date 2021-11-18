/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorme.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:23:00 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/18 20:36:50 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pxl_to_img(t_data *data, int x, int y, int color)
{
	if (data->x < WIDTH && data->y < WIDTH)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img + 4 * WIDTH * y + x * 4, &color, sizeof(int));
	}
}
