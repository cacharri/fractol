/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:46:14 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/29 19:16:12 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	parseo(int argc, char **argv)
{
	if (argc < 2)
		write (1, "Not enough arguments\n", 21);
	if (argc > 2)
		write (1, "Too many arguments\n", 19);
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "Julia", 6) != 0 && ft_strncmp(argv[1],
				"Mandelbrot", 11) != 0)
			write (1, "You have to write 'Julia' or 'Mandelbrot'\n", 42);
	}
}

int	main(int argc, char **argv)
{
	t_you	yu;

	parseo(argc, argv);
	init(&yu);
	yu.data.mlx = mlx_init();
	yu.data.win = mlx_new_window(yu.data.mlx, WIDTH, HEIGHT, "FRACT-OL");
	yu.data.img = mlx_new_image(yu.data.mlx, WIDTH, HEIGHT);
	mlx_put_image_to_window(yu.data.mlx, yu.data.win, yu.data.img, 0, 0);
	if (argc == 2 && !ft_strncmp(argv[1], "Julia", 6))
		mlx_loop_hook(yu.data.mlx, julia, &yu);
	if (argc == 2 && !ft_strncmp(argv[1], "Mandelbrot", 11))
		mlx_loop_hook(yu.data.mlx, mandel, &yu);
	mlx_hook(yu.data.win, 4, 0, rat, &yu);
	mlx_hook(yu.data.win, 5, 0, rat, &yu);
	mlx_hook(yu.data.win, 2, (0L << 0), touch, &yu);
	mlx_hook(yu.data.win, 3, (0L << 0), free_touch, &yu);
	yu.data.addr = mlx_get_data_addr(yu.data.img, &yu.data.bits_per_pixel,
			 &yu.data.line_lenght, &yu.data.endian);
	mlx_loop(yu.data.mlx);
	return (0);
}
