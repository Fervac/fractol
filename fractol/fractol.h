/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:17:55 by abechet           #+#    #+#             */
/*   Updated: 2019/02/06 11:54:36 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "define.h"
# include <math.h>
# include <mlx.h>
# include "pthread.h"

# define HEIGHT 		600
# define WIDTH			600
# define THREAD_WIDTH 	5
# define THREAD_NUMBER 	120
# define TITLE 			"Fractol"

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	void			*img_data;
	int				bpp;
	int				sizeline;
	int				endian;
	int				fractal;
	int				x;
	int				y;
	int				y_max;
	int				iter;
	int				iter_max;
	int				menu;
	int				julia_mouse;
	unsigned int	color;
	double			zoom;
	double			x_new;
	double			y_new;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;
}					t_mlx;

void				frac_exec(t_mlx *mlx);
void				mandelbrot_init(t_mlx *mlx);
void				*mandelbrot(void *tab);
void				mandelbrot_pthread(t_mlx *mlx);
void				julia_init(t_mlx *mlx);
void				*julia(void *tab);
void				julia_pthread(t_mlx *mlx);
int					mouse_julia(int x, int y, t_mlx *mlx);
void				burningship_init(t_mlx *mlx);
void				burningship_pthread(t_mlx *mlx);
void				set_error(t_mlx *mlx);
void				put_pxl_to_img(t_mlx *mlx, int x, int y, int color);
void				help(t_mlx *mlx, unsigned color);
int					get_input(int key, t_mlx *mlx);
int					mouse_hook(int key, int x, int y, t_mlx *mlx);

#endif
