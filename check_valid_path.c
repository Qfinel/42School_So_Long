/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:36:17 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/15 14:50:14 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_spaw_pos(t_vars *vars)
{
	vars->x = 0;
	vars->y = 0;
	while (vars->map[vars->y])
	{
		while (vars->map[vars->y][vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'P')
				return ;
			vars->x++;
		}
		vars->x = 0;
		vars->y++;
	}
}

void	recursive_checking(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == '1' &&
		vars->map[y][x] == 0)
		return ;
	if (vars->map[y][x] == 'C')
		vars->food_check++;
	if (vars->map[y][x] == 'E')
		vars->exit_check = 1;
	vars->map[y][x] = 'a';
	if (vars->map[y][x + 1] != '1' &&
		vars->map[y][x + 1] != 'a')
		recursive_checking(vars, x + 1, y);
	if (vars->map[y + 1][x] != '1' &&
		vars->map[y + 1][x] != 'a')
		recursive_checking(vars, x, y + 1);
	if (vars->map[y][x - 1] != '1' &&
		vars->map[y][x - 1] != 'a')
		recursive_checking(vars, x - 1, y);
	if (vars->map[y - 1][x] != '1' &&
		vars->map[y - 1][x] != 'a')
		recursive_checking(vars, x, y - 1);
}

int	check_valid_path(t_vars *vars)
{
	vars->food_check = 0;
	vars->exit_check = 0;
	get_spaw_pos(vars);
	recursive_checking(vars, vars->x, vars->y);
	if (vars->exit_check == 1 && vars->food_check == vars->food_num)
		return (1);
	return (0);
}
