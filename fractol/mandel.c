/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:41:13 by abechet           #+#    #+#             */
/*   Updated: 2019/01/29 12:13:56 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_pthread(t_mlx *mlx)
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
		pthread_create(&t[i], NULL, mandelbrot, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void	mandelbrot_init(t_mlx *mlx)
{
	mlx->menu = 0;
	mlx->iter_max = 50;
	mlx->zoom = 300;
	mlx->x_new = -2.05;
	mlx->y_new = -1.3;
	mlx->color = 775;
}

void	mandelbrot_algo(t_mlx *mlx)
{
	mlx->c_r = mlx->x / mlx->zoom + mlx->x_new;
	mlx->c_i = mlx->y / mlx->zoom + mlx->y_new;
	mlx->z_r = 0;
	mlx->z_i = 0;
	mlx->iter = 0;
	while (mlx->z_r * mlx->z_r + mlx->z_i *
			mlx->z_i < 4 && mlx->iter < mlx->iter_max)
	{
		mlx->tmp = mlx->z_r;
		mlx->z_r = mlx->z_r * mlx->z_r -
			mlx->z_i * mlx->z_i + mlx->c_r;
		mlx->z_i = 2 * mlx->z_i * mlx->tmp + mlx->c_i;
		mlx->iter++;
	}
	if (mlx->iter == mlx->iter_max)
		put_pxl_to_img(mlx, mlx->x, mlx->y, 0x808080);
	else
		put_pxl_to_img(mlx, mlx->x, mlx->y, (mlx->color * (mlx->iter / 2)));
}

void	*mandelbrot(void *tab)
{
	t_mlx	*mlx;
	int		tmp;

	mlx = (t_mlx *)tab;
	mlx->x = 0;
	tmp = mlx->y;
	while (mlx->x < WIDTH)
	{
		mlx->y = tmp;
		while (mlx->y < mlx->y_max)
		{
			mandelbrot_algo(mlx);
			mlx->y++;
		}
		mlx->x++;
	}
	return (tab);
}
