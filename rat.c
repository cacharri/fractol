/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:00:51 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/29 16:48:54 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		rat(int key, int x, int y, t_you *yu)
{
	x = 0;
	y = 0;
	if (key == 5)
		yu->vars.zoom += 0.04;
	if (key == 4)
		yu->vars.zoom -= 0.04;
	return (0);
}
