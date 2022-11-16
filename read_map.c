/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:24:23 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/16 16:58:14 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_food(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (vars->map[y])
	{
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'C')
				vars->food_num++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	put_things(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->wall, vars->x, vars->y);
		create_block(vars);
	}
	if (vars->map[i][j] == 'E')
	{
		create_block(vars);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->exit, vars->x, vars->y);
	}
	if (vars->map[i][j] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->food, vars->x + 8, vars->y + 8);
	}
	if (vars->map[i][j] == 'P')
	{
		vars->cat_x = vars->x;
		vars->cat_y = vars->y;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->cat, vars->x, vars->y);
	}
}

void	read_map(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	vars->x = 64;
	vars->y = 64;
	while (vars->map[i])
	{
		while (vars->map[i][j])
		{
			put_things(vars, i, j);
			j++;
			vars->x += 32;
		}
		j = 0;
		i++;
		vars->x = 64;
		vars->y += 32;
	}
	vars->x = 64;
	vars->y = 64;
}
