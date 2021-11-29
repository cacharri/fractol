/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:25:22 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/29 13:30:53 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <complex.h>
#include <stdio.h>
#include <math.h>
#include "key.h"
#include "libft/libft.h"

# define HEIGHT 1500
# define WIDTH 1500

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		w;
	int		s;
	int		d;
	int		a;
	//int		x;
	//int		y;
}				t_data;

typedef struct s_vars {
	double	real;
	double	ymag;
	double	nreal;
	double	nymag;
	double	olreal;
	double	olymag;
	double	zoom;
	double	movx;
	double	movy;
	int		maxiter;
	char	change;
}				t_vars;

typedef struct s_you {
	t_data	data;
	t_vars	vars;
}				t_you;

void	my_mlx_pixel_put(t_you *yu, int x, int y, int color);
int		rat(int key, int x, int y, t_vars *vars);
int		move(t_data *dat, t_vars *var);
int		exit_touch(t_data *dat);
int		free_touch(int keydo, t_data *dat);
int		touch(int keydo, t_data *dat);
int		init(t_you *yu);
void	put_pxl_to_img(t_data *data, int x, int y, int color);
int		colorme(int r, int g, int b);

#endif
