/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:47:02 by abechet           #+#    #+#             */
/*   Updated: 2019/02/06 11:59:16 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		frac_exec(t_mlx *mlx)
{
	if (mlx->fractal == 1)
		mandelbrot_pthread(mlx);
	if (mlx->fractal == 2)
		julia_pthread(mlx);
	if (mlx->fractal == 3)
		burningship_pthread(mlx);
}

void		put_pxl_to_img(t_mlx *mlx, int x, int y, int color)
{
	if (mlx->x < WIDTH && mlx->y < WIDTH)
	{
		color = mlx_get_color_value(mlx->mlx_ptr, color);
		ft_memcpy(mlx->img_data + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

static void	check_fractal(t_mlx *mlx, char *name)
{
	if (!ft_strcmp(name, "Mandelbrot"))
	{
		mlx->fractal = 1;
		mandelbrot_init(mlx);
		mandelbrot_pthread(mlx);
	}
	if (!ft_strcmp(name, "Julia"))
	{
		mlx->fractal = 2;
		julia_init(mlx);
		julia_pthread(mlx);
	}
	if (!ft_strcmp(name, "Burningship"))
	{
		mlx->fractal = 3;
		burningship_init(mlx);
		burningship_pthread(mlx);
	}
}

static int	set_window(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		set_error(mlx);
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH,
					HEIGHT, TITLE)))
		set_error(mlx);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->img_data = mlx_get_data_addr(mlx->img_ptr,
			&mlx->bpp, &mlx->sizeline, &mlx->endian);
	return (1);
}

int			main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac != 2 || (ft_strcmp(av[1], "Mandelbrot") != 0
		&& ft_strcmp(av[1], "Julia") != 0 && ft_strcmp(av[1],
			"Burningship") != 0))
	{
		ft_putendl("usage: ./fractol [Fractal Name]");
		ft_putendl("Name : [Mandelbrot] [Julia] [Burningship]");
		exit(EXIT_FAILURE);
	}
	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		set_error(NULL);
	if (!(set_window(mlx)))
		set_error(mlx);
	check_fractal(mlx, av[1]);
	mlx_hook(mlx->win_ptr, 6, 1L < 6, mouse_julia, mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse_hook, mlx);
	mlx_hook(mlx->win_ptr, 2, 3, get_input, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
