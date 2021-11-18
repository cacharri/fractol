/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:46:14 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/18 20:36:53 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = (char *)data->addr + (y * data->line_lenght + x 
			* (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
*/
static	void	init(t_vars *vars)
{
	ft_bzero(vars, sizeof(t_vars));
	vars->maxiter = 300;
	vars->real = -0.7;
	vars->ymag = 0.27015;
	vars->zoom = 1;
	//vars->color = 265;
}

static	int	julia_init(t_vars *vars, int x, int y)
{
	vars->nreal = 1.5 * (x - WIDTH / 2) / (0.5 * vars->zoom * WIDTH)
	   	+ vars->movx;
	vars->nymag = (y - HEIGHT / 2) / (0.5 * vars->zoom * HEIGHT) + vars->movy;
	return (0);
}

static	void	julia_actual(t_vars *var)
{

	var->olreal = var->nreal;
	var->olymag = var->nymag;
	var->nreal = var->olreal * var->olreal - var->olymag * var->olymag 
		+ var->real;
	var->nymag = 2 * var->olreal * var->olymag + var->ymag;
}

static	int	julia(t_data *data, t_vars *var)
{
	int	j;

	data->y = 0;
	data->color = 265;
	mlx_do_sync(data->mlx);
	while (data->y < HEIGHT)
	{
		data->x = 0;
		while (data->x < WIDTH)
		{
			j = julia_init(var, data->x, data->y);
			while (j++ < var->maxiter)
			{
				julia_actual(var);
				if ((var->nreal * var->nreal + var->nymag * var->nymag) > 4)
					break;
				if (j == var->maxiter)
					put_pxl_to_img(data, data->x, data->y, 0x000000);
				else
					put_pxl_to_img(data, data->x, data->y, (data->color * j));
			}
			//my_mlx_pixel_put(data, data->x, data->y, mlx_get_color_value(data->mlx, 0x000000));
			data->x += 1;
		}
		data->y += 1;
	}
	move(data, var);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

static	int	parseo(int argc, char **argv)
{

	if (argc < 2)
		write (1, "Not enough arguments\n", 21);
	if (argc > 2)
		write (1, "Too many arguments\n", 19);
	if (argc == 2)
	{
		if (ft_strncmp(argv[1],  "Julia", 6) != 0 && ft_strncmp(argv[1],
				   	"Mandelbrot", 11) != 0)
			write (1, "You have to write 'Julia' or 'Mandelbrot'\n", 42);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	dat;
	t_vars	var;

	parseo(argc, argv);
	init(&var);
	dat.mlx = mlx_init();
	dat.win = mlx_new_window(dat.mlx, WIDTH, HEIGHT, "FRACT-OL");
	dat.img = mlx_new_image(dat.mlx, WIDTH, HEIGHT);
	dat.addr = mlx_get_data_addr(dat.img, &dat.bits_per_pixel,
			 &dat.line_lenght, &dat.endian);
	if(argc == 2 && !ft_strncmp(argv[1], "Julia", 6))
		mlx_loop_hook(dat.mlx, julia, &dat);
	mlx_hook(dat.win, UP_MOUSE, 0, rat, &var);
	mlx_hook(dat.win, DOWN_MOUSE, 0, rat, &var);
	mlx_hook(dat.win, 2, (0L << 0), touch, &dat);
	mlx_hook(dat.win, 3, (0L << 0), free_touch, &dat);
	mlx_hook(dat.win, 17, (17L << 0), exit_touch, &dat);
	mlx_loop(dat.mlx);
	/*
		mlx_put_image_to_window(dat.mlx, dat.win, dat.img, 0, 0);
		mlx_loop(img.mlx);*/	
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	return (0);
}
