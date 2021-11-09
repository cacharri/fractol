/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:46:14 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/09 21:50:08 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		key_hook(int keycode, t_vars *vars)
{
	vars = ft_calloc(1, sizeof(t_vars));
	keycode = 0;
	printf("Hello from key_hook!\n");
	return (0);
}


int	julia(t_data *data, t_vars *var)
{
	int				x;
	int				y;
	double _Complex	z;
	float _Complex	c = 2.0f + 2.0f*_Complex_I;

	y = 0;
	x = 0;
	mlx_do_sync(data->mlx);
	while (y <= HEIGHT)
	{
		while (x <= WIDTH)
		{
		}
	}
	return (0);

}

int	main(int argc, char **argv)
{
	t_data	img;
	t_vars	vars;
	int		maxIterations;


	maxIterations = 100;
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
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "FRACT-OL");
		img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
		vars.addr = mlx
		mlx_key_hook(vars.win, key_hook, &vars);
		mlx_loop(vars.mlx);
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
		mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
		mlx_loop(img.mlx);*/
	}
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	return (0);
}
