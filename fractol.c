/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:46:14 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/16 21:04:54 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = (char *)data->addr + (y * data->line_lenght + x 
			* (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		key_hook(int keycode, t_vars *vars)
{
	vars = ft_calloc(1, sizeof(t_vars));
	keycode = 0;
	printf("Hello from key_hook!\n");
	return (0);
}

int	julia_init(t_vars *vars, int x, int y)
{
	vars->nreal = 1.5 * (x - WIDTH / 2) / (0.5 * vars->zoom * WIDTH)
	   	+ vars->movx;
	vars->nymag = (y - HEIGHT / 2) / (0.5 * vars->zoom * HEIGHT) + vars->movy;
	return (-1);
}

void	julia_actual(t_vars *var)
{

	var->olreal = var->nreal;
	var->olymag = var->olymag;
	var->nreal = var->olreal * var->olreal - var->olymag * var->olymag 
		+ var->real;
	var->nymag = 2 * var->olreal * var->olymag + var->ymag;
	
}

int	julia(t_data *data, t_vars *var)
{
	int	j;
	int	x;
	int	y;

	y = 0;
	x = 0;
	j = 0;
	var->maxiter = 300;
	var->real = -0.7;
	var->ymag = 0.27015;
	var->zoom = 1;
	mlx_do_sync(data->mlx);
	while (y++ <= HEIGHT)
	{
		while (x++ <= WIDTH)
		{
			j = julia_init(var, x, y);
			while (++j < var->maxiter)
			{
				julia_actual(var);
				if ((var->nreal * var->nreal + var->nymag *var->nymag) > 4)
					break;
			}
			my_mlx_pixel_put(data, x, y, 0x00FF0000);
		}

	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);

}

int	main(int argc, char **argv)
{
	t_data	dat;
	t_vars	var;

	printf("%d\n", argc);
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
	if(argc == 2 && !ft_strncmp(argv[1], "Julia", 6))
	{
		ft_bzero(&dat, sizeof(t_data));
		ft_bzero(&var, sizeof(t_vars));
		dat.mlx = mlx_init();
		dat.win = mlx_new_window(dat.mlx, WIDTH, HEIGHT, "FRACT-OL");
		dat.img = mlx_new_image(dat.mlx, WIDTH, HEIGHT);
		dat.addr = mlx_get_data_addr(dat.img, &dat.bits_per_pixel,
				 &dat.line_lenght, &dat.endian);
	//	mlx_key_hook(vars.win, key_hook, &vars);
		mlx_loop_hook(dat.mlx, julia, &dat);
		mlx_loop(dat.mlx);
		/*
		img.mlx = mlx_init();
		img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
		img.img = mlx_new_image(img.mlx, 1080, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght,
								&img.endian);
		my_mlx_pixel_put(&img, 200, 50, 0x00FFFF00);
		my_mlx_pixel_put(&img, 300, 100, 0x00FFFF00);
		my_mlx_pixel_put(&img, 400, 150, 0x00FFFF00);
		my_mlx_pixel_put(&img, 500, 200, 0x00FFFF00);
		my_mlx_pixel_put(&img, 600, 250, 0x00FFFF00);

		mlx_put_image_to_window(dat.mlx, dat.win, dat.img, 0, 0);
		mlx_loop(img.mlx);*/
	}
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	return (0);
}
