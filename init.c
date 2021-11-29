/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:47:58 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/29 17:02:47 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int init(t_you *yu)
{
	ft_bzero(&yu->vars, sizeof(yu->vars));
	ft_bzero(&yu->data, sizeof(yu->data));
	yu->vars.maxiter = 300;
	yu->vars.real = -0.7;
	yu->vars.ymag = 0.27015;
	yu->vars.zoom = 1;
	yu->data.color = colorme(0, 255, 0);
	return (0);
 }
