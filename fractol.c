/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:46:14 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/23 19:21:31 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_you *yu, int x, int y, int color)
{
	char	*dst;

	dst = yu->data->addr + (y * yu->data->line_lenght + x 
			* (yu->data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init(t_you *yu)
{
	ft_bzero(yu->vars, sizeof(t_vars));
	yu->vars->maxiter = 300;
	yu->vars->real = -0.7;
	yu->vars->ymag = 0.27015;
	yu->vars->zoom = 1;
}

int	julia_init(t_you *yu)
{
	yu->vars->nreal = 1.5 * (yu->data->x - WIDTH / 2) / (0.5 * yu->vars->zoom * WIDTH)
	   	+ yu->vars->movx;
	yu->vars->nymag = (yu->data->y - HEIGHT / 2) / (0.5 * yu->vars->zoom * HEIGHT) + yu->vars->movy;
	return (0);
}

void	julia_actual(t_you *yu)
{

	yu->vars->olreal = yu->vars->nreal;
	yu->vars->olymag = yu->vars->nymag;
	yu->vars->nreal = yu->vars->olreal * yu->vars->olreal - yu->vars->olymag * yu->vars->olymag 
		+ yu->vars->real;
	yu->vars->nymag = 2 * yu->vars->olreal * yu->vars->olymag + yu->vars->ymag;
}

int	julia(t_you *yu)
{
	// int	j;

	// data->y = 0;
	// mlx_do_sync(data->mlx);
	// while (data->y < HEIGHT)
	// {
	// 	data->x = 0;
	// 	while (data->x < WIDTH)
	// 	{
	// 		j = julia_init(var, data);
	// 		while (j++ < var->maxiter)
	// 		{
	// 			julia_actual(var);
	// 			if ((var->nreal * var->nreal + var->nymag * var->nymag) > 4)
	// 				break;
	// 			/*
	// 			if (j == var->maxiter)
	// 				put_pxl_to_img(data, data->x, data->y, 0x000000);
	// 			else
	// 				put_pxl_to_img(data, data->x, data->y, (data->color * j));
	// 				*/
	// 		}
	// 		my_mlx_pixel_put(data, data->x, data->y, colorme(0, 255, 0));
	// 		data->x += 1;
	// 	}
	// 	data->y += 1;
	// }
	// // write(1, "HEY\n", 4);
	// //move(data, var);
	// mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	// var->change = 0;
	// return (0);



	int	j;

	printf("VARIABLE%d\n", yu->var->maxiter);

	yu->data->y = 0;
	mlx_do_sync(yu->data->mlx);
	while (yu->data->y < HEIGHT)
	{
		yu->data->x = 0;
		while (yu->data->x < WIDTH)
		{
			j = julia_init(var, data);
			while (j++ < yu->var->maxiter)
			{
				write(1, "1\n", 2);
				julia_actual(yu);
				if ((yu->var->nreal * yu->var->nreal + yu->var->nymag * yu->var->nymag) > 4)
					break;
				/*
				if (j == var->maxiter)
					put_pxl_to_img(data, data->x, data->y, 0x000000);
				else
					put_pxl_to_img(data, data->x, data->y, (data->color * j));
					*/
			}
			my_mlx_pixel_put(data, data->x, data->y, colorme(0, 255, 0));
			yu->data->x += 1;
		}
		yu->data->y += 1;
	}
	// write(1, "HEY\n", 4);
	//move(data, var);
	mlx_put_image_to_window(yu->data->mlx, yu->data->win, yu->data->img, 0, 0);
	yu->var->change = 0;
	return (0);
}

int	render_frame(t_you *yu)
{
	if (yu->var->change)
	{
		julia(yu);
	}
	return(0);
}

static	void	parseo(int argc, char **argv)
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
}

int	main(int argc, char **argv)
{
	t_you	*yu;

	parseo(argc, argv);
	init(&yu);
	yu->vars.change = 1; // ESTO ES MIERDA DE GUTTEN
	yu->data.mlx = mlx_init();
	yu->data.win = mlx_new_window(yu->data.mlx, WIDTH, HEIGHT, "FRACT-OL");
	yu->data.img = mlx_new_image(yu->data.mlx, WIDTH, HEIGHT);
	if(argc == 2 && !ft_strncmp(argv[1], "Julia", 6))
		mlx_loop_hook(yu.data.mlx, render_frame, &yu);
	julia(&yu);
	//mlx_hook(dat.win, UP_MOUSE, 0, rat, &var);
	//mlx_hook(dat.win, DOWN_MOUSE, 0, rat, &var);
	//mlx_hook(dat.win, 2, (0L << 0), touch, &dat);
	//mlx_hook(dat.win, 3, (0L << 0), free_touch, &dat);
	//mlx_hook(dat.win, 17, (17L << 0), exit_touch, &dat);

	yu->data.addr = mlx_get_data_addr(yu->data.img, &yu->data.bits_per_pixel,
			 &yu->data.line_lenght, &yu->data.endian);
	mlx_put_image_to_window(yu->data.mlx, yu->data.win, yu->data.img, 0, 0);
	mlx_loopyu(yu->data.mlx);
	/*
		mlx_loop(img.mlx);*/	
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	return (0);
}
