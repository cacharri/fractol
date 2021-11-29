/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:47:58 by ialvarez          #+#    #+#             */
/*   Updated: 2021/11/29 13:30:48 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int init(t_you *yu)
{
	//write(1, "sas\n", 4);
	ft_bzero(yu->vars, sizeof(yu->vars));
	yu->vars.maxiter = 300;
	yu->vars.real = -0.7;
	yu->vars.ymag = 0.27015;
	yu->vars.zoom = 1;
	return (0);
 }
