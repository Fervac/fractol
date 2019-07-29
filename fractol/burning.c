/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:05:52 by abechet           #+#    #+#             */
/*   Updated: 2019/02/25 14:06:06 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burningship_init(t_mlx *mlx)
{
	mlx->iter_max = 50;
	mlx->zoom = 220;
	mlx->x_new = -2.2;
	mlx->y_new = -2.5;
	mlx->color = 265;
}

void	burningship_algo(t_mlx *mlx)
{
	mlx->c_r = mlx->x / mlx->zoom + mlx->x_new;
	mlx->c_i = mlx->y / mlx->zoom + mlx->y_new;
	mlx->z_r = 0;
	mlx->z_i = 0;
	mlx->iter = 0;
	while (mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4
			&& mlx->iter < mlx->iter_max)
	{
		mlx->tmp = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
		mlx->z_i = fabs(2 * mlx->z_r * mlx->z_i) + mlx->c_i;
		mlx->z_r = mlx->tmp;
		mlx->iter++;
	}
	if (mlx->iter == mlx->iter_max)
		put_pxl_to_img(mlx, mlx->x, mlx->y, 0x000000);
	else
		put_pxl_to_img(mlx, mlx->x, mlx->y, (mlx->color * mlx->iter));
}

void	*burningship(void *tab)
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
			burningship_algo(mlx);
			mlx->y++;
		}
		mlx->x++;
	}
	return (tab);
}

void	burningship_pthread(t_mlx *mlx)
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
		pthread_create(&t[i], NULL, burningship, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}
