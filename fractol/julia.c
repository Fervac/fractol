/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:39:09 by abechet           #+#    #+#             */
/*   Updated: 2019/02/18 12:39:28 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_pthread(t_mlx *mlx)
{
	t_mlx		tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)mlx, sizeof(t_mlx));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, julia, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void	julia_init(t_mlx *mlx)
{
	mlx->menu = 0;
	mlx->iter_max = 50;
	mlx->zoom = 200;
	mlx->x_new = -2.0;
	mlx->y_new = -1.9;
	mlx->color = 265;
	mlx->c_r = 0.285;
	mlx->c_i = 0.01;
	mlx->julia_mouse = 1;
}

void	julia_algo(t_mlx *mlx)
{
	mlx->z_r = mlx->x / mlx->zoom + mlx->x_new;
	mlx->z_i = mlx->y / mlx->zoom + mlx->y_new;
	mlx->iter = 0;
	while (mlx->z_r * mlx->z_r + mlx->z_i
			* mlx->z_i < 4 && mlx->iter < mlx->iter_max)
	{
		mlx->tmp = mlx->z_r;
		mlx->z_r = mlx->z_r * mlx->z_r -
			mlx->z_i * mlx->z_i - 0.8 + (mlx->c_r / WIDTH);
		mlx->z_i = 2 * mlx->z_i * mlx->tmp + mlx->c_i / WIDTH;
		mlx->iter++;
	}
	if (mlx->iter == mlx->iter_max)
		put_pxl_to_img(mlx, mlx->x, mlx->y, 0x808080);
	else
		put_pxl_to_img(mlx, mlx->x, mlx->y, (mlx->color * mlx->iter / 2));
}

void	*julia(void *tab)
{
	int		tmp;
	t_mlx	*mlx;

	mlx = (t_mlx *)tab;
	mlx->x = 0;
	tmp = mlx->y;
	while (mlx->x < WIDTH)
	{
		mlx->y = tmp;
		while (mlx->y < mlx->y_max)
		{
			julia_algo(mlx);
			mlx->y++;
		}
		mlx->x++;
	}
	return (tab);
}
