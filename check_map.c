/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:58:14 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/12 17:21:20 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_sides(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map[i])
	{
		if (vars->map[i][0] != '1')
			return (0);
		i++;
	}
	while (vars->map[0][j])
		j++;
	j--;
	i = 0;
	while (vars->map[i])
	{
		if (vars->map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_structure(t_vars *vars)
{
	int	i;
	int	j;

	i = 1;
	j = -1;
	while (vars->map[i])
	{
		if (ft_strlen(vars->map[i - 1]) != ft_strlen(vars->map[i]))
			return (0);
		i++;
	}
	i--;
	while (vars->map[i][++j])
	{
		if (vars->map[i][j] != '1')
			return (0);
	}
	i = -1;
	while (vars->map[0][++i])
	{
		if (vars->map[0][i] != '1')
			return (0);
	}
	return (1);
}

int	count_element(t_vars *vars, char c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (vars->map[i])
	{
		while (vars->map[i][j])
		{
			if (vars->map[i][j] != '0' && vars->map[i][j] != '1' &&
				vars->map[i][j] != 'C' && vars->map[i][j] != 'E' &&
				vars->map[i][j] != 'P')
				return (0);
			if (vars->map[i][j] == c)
				n++;
			j++;
		}
		j = 0;
		i++;
	}
	return (n);
}

int	check_map(t_vars *vars)
{
	int		i;
	int		j;
	int		exit;
	int		coll;
	int		start;

	i = 0;
	j = 0;
	exit = count_element(vars, 'E');
	coll = count_element(vars, 'C');
	start = count_element(vars, 'P');
	if (!check_map_sides(vars))
		return (0);
	if (exit != 1 || start != 1 || coll < 1)
		return (0);
	if (!check_structure(vars))
		return (0);
	return (1);
}
