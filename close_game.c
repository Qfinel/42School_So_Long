/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:38:00 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/16 11:02:51 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
}

int	close_game(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->floor);
	mlx_destroy_image(vars->mlx, vars->food);
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->exit);
	mlx_destroy_image(vars->mlx, vars->cat);
	free_map(vars);
	free(vars->peppers);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	ft_printf("Game closed\n");
	exit(0);
}

void	win_game(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->floor);
	mlx_destroy_image(vars->mlx, vars->food);
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->exit);
	mlx_destroy_image(vars->mlx, vars->cat);
	free_map(vars);
	free(vars->peppers);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	ft_printf("You won!\n");
	exit(0);
}

void	return_error(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Invalid argument\n", 2);
	exit(1);
}

void	return_error_win(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->floor);
	mlx_destroy_image(vars->mlx, vars->food);
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->exit);
	mlx_destroy_image(vars->mlx, vars->cat);
	free_map(vars);
	free(vars->peppers);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Invalid map\n", 2);
	exit(1);
}
