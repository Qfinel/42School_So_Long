/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:51:45 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/16 16:58:23 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_map_len(t_vars *vars)
{
	int		x;

	x = 0;
	while (vars->map[0][x])
		x++;
	return ((x + 4) * 32);
}

int	find_map_height(t_vars *vars)
{
	int		y;

	y = 0;
	while (vars->map[y])
		y++;
	return ((y + 4) * 32);
}

void	place_floor(t_vars vars)
{
	int	x;
	int	y;
	int	max_x;
	int	max_y;

	x = 0;
	y = 0;
	max_x = find_map_len(&vars);
	max_y = find_map_height(&vars);
	while (y < max_y)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, vars.floor, x, y);
		while (x < max_x - 32)
		{
			x += 32;
			mlx_put_image_to_window(vars.mlx, vars.win, vars.floor, x, y);
		}
		x = 0;
		y += 32;
	}
}

void	create_block(t_vars *vars)
{
	if (vars->cat_x == vars->x - 32 && vars->cat_y == vars->y)
		vars->pass_right = 0;
	if (vars->cat_x == vars->x + 32 && vars->cat_y == vars->y)
		vars->pass_left = 0;
	if (vars->cat_x == vars->x && vars->cat_y == vars->y - 32)
		vars->pass_down = 0;
	if (vars->cat_x == vars->x && vars->cat_y == vars->y + 32)
		vars->pass_up = 0;
}

void	init_map(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, find_map_len(vars),
			find_map_height(vars), "so_long");
	vars->wall = mlx_xpm_file_to_image(vars->mlx,
			"img/bush.xpm", &vars->size, &vars->size);
	vars->floor = mlx_xpm_file_to_image(vars->mlx,
			"img/grass.xpm", &vars->size, &vars->size);
	vars->food = mlx_xpm_file_to_image(vars->mlx,
			"img/chili.xpm", &vars->size, &vars->size);
	vars->cat = mlx_xpm_file_to_image(vars->mlx,
			"img/cat_right.xpm", &vars->size, &vars->size);
	vars->exit = mlx_xpm_file_to_image(vars->mlx,
			"img/blackhole.xpm", &vars->size, &vars->size);
	count_food(vars);
	place_floor(*vars);
	if (!check_map(vars))
		return_error_win(vars);
	if (!check_valid_path(vars))
		return_error_win(vars);
	free_map(vars);
	create_buf(vars);
	read_map(vars);
	read_map(vars);
}
