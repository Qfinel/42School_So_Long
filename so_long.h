/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:00:42 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/16 10:53:07 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*cat;
	void	*wall;
	void	*floor;
	void	*food;
	void	*exit;
	char	**map;
	char	*map_path;
	int		steps;
	int		size;
	int		x;
	int		y;
	int		cat_x;
	int		cat_y;
	int		pass_left;
	int		pass_right;
	int		pass_up;
	int		pass_down;
	int		food_num;
	int		food_check;
	int		exit_check;
	int		*peppers;
}				t_vars;

void	read_map(t_vars *vars);
void	read_map_new(t_vars *vars);
void	count_food(t_vars *vars);
void	create_buf(t_vars *vars);
void	move_left(t_vars *vars);
void	move_up(t_vars *vars);
void	move_right(t_vars *vars);
void	move_down(t_vars *vars);
void	win_game(t_vars *vars);
int		check_ext(char *str);
int		close_game(t_vars *vars);
int		check_map(t_vars *vars);
int		check_valid_path(t_vars *vars);
int		find_map_len(t_vars *vars);
int		find_map_height(t_vars *vars);
void	recursive_checking(t_vars *vars, int x, int y);
void	get_spaw_pos(t_vars *vars);
void	place_floor(t_vars vars);
int		pressed(int keycode, t_vars *vars);
void	return_error(void);
void	init_map(t_vars *vars);
void	free_map(t_vars *vars);
void	return_error_win(t_vars *vars);
void	render_things(t_vars *vars, int i, int j, int n);
void	render_food(t_vars *vars, int n);
void	create_block(t_vars *vars);
int		render_next_frame(t_vars *vars);

#endif