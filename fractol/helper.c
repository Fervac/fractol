/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:52:25 by abechet           #+#    #+#             */
/*   Updated: 2019/02/15 16:52:46 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help(t_mlx *mlx, unsigned color)
{
	short		x;

	x = 15;
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, color,
			"Zoom : [left click] [scroll up]");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 35, color,
			"Dezoom : [right click] [scroll down]");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 60, color,
			"Increase/Decrease current iteration : [+] [-]");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 85, color,
			"Increase/Decrease color : [W] [S]");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 110, color,
			"Random color in range : [R]");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 135, color,
			"Julia Mouse ON / OFF : [M]");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 175, color,
			"Exit : [ESCAPE]");
}
