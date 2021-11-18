/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:25:22 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/18 20:21:40 by ialvarez         ###   ########.fr       */
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

# define HEIGHT 1080
# define WIDTH 1920

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
	int		x;
	int		y;
	int		color;
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
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		rat(int key, int x, int y, t_vars *vars);
int		move(t_data *dat, t_vars *var);
int		exit_touch(t_data *dat);
int		free_touch(int keydo, t_data *dat);
int		touch(int keydo, t_data *dat);
void	put_pxl_to_img(t_data *data, int x, int y, int color);

#endif
