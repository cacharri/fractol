/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:25:22 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/29 17:03:11 by ialvarez         ###   ########.fr       */
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

# define HEIGHT 1422
# define WIDTH 1422

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

typedef struct s_you {
	t_data	data;
	t_vars	vars;
}				t_you;

void	my_mlx_pixel_put(t_you *yu, int x, int y, int color);
int		rat(int key, int x, int y, t_you *yu);
int		move(t_you *yu);
int		free_touch(int keydo, t_you *yu);
int		touch(int keydo, t_you *yu);
int		init(t_you *yu);
int		colorme(int r, int g, int b);

#endif
