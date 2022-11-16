/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:38:46 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/15 15:33:14 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->cat);
	vars->cat = mlx_xpm_file_to_image(vars->mlx,
			"img/cat_left.xpm", &vars->size, &vars->size);
	vars->cat_x -= vars->size;
	vars->steps++;
	ft_printf("Steps: %d\n", vars->steps);
}

void	move_up(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->cat);
	vars->cat = mlx_xpm_file_to_image(vars->mlx,
			"img/cat_up.xpm", &vars->size, &vars->size);
	vars->cat_y -= vars->size;
	vars->steps++;
	ft_printf("Steps: %d\n", vars->steps);
}

void	move_right(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->cat);
	vars->cat = mlx_xpm_file_to_image(vars->mlx,
			"img/cat_right.xpm", &vars->size, &vars->size);
	vars->cat_x += vars->size;
	vars->steps++;
	ft_printf("Steps: %d\n", vars->steps);
}

void	move_down(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->cat);
	vars->cat = mlx_xpm_file_to_image(vars->mlx,
			"img/cat_down.xpm", &vars->size, &vars->size);
	vars->cat_y += vars->size;
	vars->steps++;
	ft_printf("Steps: %d\n", vars->steps);
}

int	pressed(int keycode, t_vars *vars)
{
	if (keycode == 53)
		close_game(vars);
	if (keycode == 0 && vars->pass_left == 1)
		move_left(vars);
	if (keycode == 1 && vars->pass_down == 1)
		move_down(vars);
	if (keycode == 2 && vars->pass_right == 1)
		move_right(vars);
	if (keycode == 13 && vars->pass_up == 1)
		move_up(vars);
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		render_next_frame(vars);
	return (0);
}
