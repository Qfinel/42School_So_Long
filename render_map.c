/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:41:10 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/15 14:37:21 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_food(t_vars *vars, int n)
{
	if (vars->cat_x == vars->x && vars->cat_y == vars->y)
	{
		vars->peppers[n] = -1;
		vars->food_num--;
	}
	else
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->food, vars->x + 8, vars->y + 8);
}

void	render_things(t_vars *vars, int i, int j, int n)
{
	if (vars->map[i][j] == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->wall, vars->x, vars->y);
		create_block(vars);
	}
	if (vars->map[i][j] == 'E')
	{
		if (vars->food_num > 0)
			create_block(vars);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->exit, vars->x, vars->y);
		if (vars->cat_x == vars->x && vars->cat_y == vars->y)
			win_game(vars);
	}
	if (vars->map[i][j] == 'C' && vars->peppers[n] == 1)
		render_food(vars, n);
}

void	read_map_new(t_vars *vars)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	n = 0;
	while (vars->map[i])
	{
		while (vars->map[i][j])
		{
			render_things(vars, i, j, n);
			if (vars->map[i][j] == 'C')
				n++;
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
