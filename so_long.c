/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:00:16 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/16 11:04:35 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ext(char *str)
{
	if (ft_strncmp(ft_strrchr(str, '.'), ".ber", 5) == 0)
		return (1);
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	place_floor(*vars);
	vars->pass_left = 1;
	vars->pass_right = 1;
	vars->pass_up = 1;
	vars->pass_down = 1;
	read_map_new(vars);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->cat, vars->cat_x, vars->cat_y);
	return (0);
}

void	create_buf(t_vars *vars)
{
	char	*s;
	char	*str;
	int		fd;
	int		i;

	fd = open(vars->map_path, O_RDONLY);
	if (read(fd, 0, 0) < 0)
		return_error();
	str = ft_calloc(1, sizeof(char));
	s = ft_calloc(1, sizeof(char));
	i = 1;
	while (i > 0)
	{
		i = read(fd, s, 1);
		if (i > 0)
			str = ft_strjoin(str, s);
	}
	vars->map = ft_split(str, '\n');
	close(fd);
	free(s);
	free(str);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		i;

	if (argc != 2 || !check_ext(argv[1]))
		return_error();
	i = 0;
	vars.map_path = argv[1];
	create_buf(&vars);
	vars.size = 32;
	vars.steps = 0;
	vars.food_num = 0;
	vars.pass_left = 1;
	vars.pass_right = 1;
	vars.pass_up = 1;
	vars.pass_down = 1;
	init_map(&vars);
	vars.peppers = ft_calloc(sizeof(int), vars.food_num);
	while (i < vars.food_num)
		vars.peppers[i++] = 1;
	ft_printf("Steps: %d\n", vars.steps);
	mlx_hook(vars.win, 2, 1L << 0, pressed, &vars);
	mlx_hook(vars.win, 17, 0, close_game, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
