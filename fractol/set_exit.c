/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:54:54 by abechet           #+#    #+#             */
/*   Updated: 2019/02/12 10:55:39 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_error(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->img_ptr && mlx->mlx_ptr)
			mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		if (mlx->win_ptr && mlx->mlx_ptr)
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->mlx_ptr = NULL;
		mlx->win_ptr = NULL;
		mlx->img_ptr = NULL;
		mlx->img_data = NULL;
		free(mlx);
		mlx = NULL;
	}
	exit(EXIT_SUCCESS);
}
