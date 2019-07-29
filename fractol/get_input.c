/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:08:56 by abechet           #+#    #+#             */
/*   Updated: 2019/02/06 13:10:12 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_pad(int key, t_mlx *mlx)
{
	if (key == KEY_W)
		mlx->color += 5;
	if (key == KEY_S)
		mlx->color -= 5;
	if (key == KEY_H)
	{
		if (mlx->menu == 1)
			mlx->menu = 0;
		else
			mlx->menu = 1;
	}
	if (key == KEY_M)
	{
		if (mlx->julia_mouse == 1)
			mlx->julia_mouse = 0;
		else
			mlx->julia_mouse = 1;
	}
	if (key == KEY_R)
		mlx->color = rand() % 255;
}

static void	zoom_dezoom(int key, int x, int y, t_mlx *mlx)
{
	if (key == LEFT_CLICK || key == SCROLL_UP)
	{
		mlx->x_new = (x / mlx->zoom + mlx->x_new) - (x / (mlx->zoom * 1.3));
		mlx->y_new = (y / mlx->zoom + mlx->y_new) - (y / (mlx->zoom * 1.3));
		mlx->zoom *= 1.3;
		mlx->iter_max++;
	}
	if (key == RIGHT_CLICK || key == SCROLL_DOWN)
	{
		mlx->x_new = (x / mlx->zoom + mlx->x_new) - (x / (mlx->zoom / 1.3));
		mlx->y_new = (y / mlx->zoom + mlx->y_new) - (y / (mlx->zoom / 1.3));
		mlx->zoom /= 1.3;
		mlx->iter_max--;
	}
}

int			mouse_julia(int x, int y, t_mlx *mlx)
{
	if (mlx->fractal == 2 && mlx->julia_mouse == 1)
	{
		mlx->c_r = x * 2;
		mlx->c_i = y * 2 - 800;
		frac_exec(mlx);
		if (mlx->menu == 1)
			help(mlx, 0xFFFFFF);
	}
	return (0);
}

int			mouse_hook(int key, int x, int y, t_mlx *mlx)
{
	if (key == LEFT_CLICK || key == RIGHT_CLICK
		|| key == SCROLL_UP || key == SCROLL_DOWN)
		zoom_dezoom(key, x, y, mlx);
	frac_exec(mlx);
	if (mlx->menu == 1)
		help(mlx, 0xFFFFFF);
	return (0);
}

int			get_input(int key, t_mlx *mlx)
{
	if (key == KEY_PAD_ADD)
		mlx->iter_max += 10;
	if (key == KEY_PAD_SUB)
	{
		if (mlx->iter_max >= 60)
			mlx->iter_max -= 10;
	}
	if (key == KEY_W || key == KEY_S || key == KEY_H ||
		key == KEY_M || key == KEY_R)
		key_pad(key, mlx);
	if (key == KEY_ESCAPE)
		set_error(mlx);
	frac_exec(mlx);
	if (mlx->menu == 1)
		help(mlx, 0xFFFFFF);
	return (0);
}
