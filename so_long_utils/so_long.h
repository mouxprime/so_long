/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:23:28 by mianni            #+#    #+#             */
/*   Updated: 2024/09/16 17:03:38 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../GNL/get_next_line.h"
# include "../libft/sources/libft.h"
# include "../minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>

# define COLLECTIBLE "files/collectible.xpm"
# define PLAYER "files/player.xpm"
# define EXIT_C "files/exit_c.xpm"
# define EXIT_O "files/exit_o.xpm"
# define FLOOR "files/floor.xpm"
# define ENNEMI "files/ennemi.xpm"
# define WALL "files/wall.xpm"
# define PLAYER_R "files/player_right.xpm"
# define WIDTH 30
# define HEIGHT 30

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*floor;
	void	*ennemi;
	void	*sprite;
	void	*sprite_r;
	void	*exit_c;
	void	*exit_o;
	void	*wall;
	void	*collectible;
	char	**array;
	int		collectibles;
	int		exit;
	int		players;
	int		player_height;
	int		player_width;
	int		ennemi_height;
	int		ennemi_width;
	int		move_right;
	size_t	height;
	size_t	width;
	size_t	move;
}			t_data;

bool		parsing(t_data *map, int fd, char *argv);

t_data		*start_struct(void);

bool		check_all_width(t_data *map);

void		setup_data(t_data *map);

void		print_map(char **str);

char		*copy_line(int fd);

bool		check_input_file(char **argv, int fd);

bool		launch_minilibx(t_data *map);

int			destroy_window(t_data *map);

char		**setup_map_array(t_data *map, int fd, char *argv);

int			hooks_setup(int key, t_data *map);

void		setup_images(t_data *map);

void		print_images(t_data *map, int i, int j);

void		move_down(t_data *map);

void		move_up(t_data *map);

void		move_left(t_data *map);

void		move_right(t_data *map);

void		check_player_position(t_data *map);

void		close_and_clear(char **map_array, int fd, t_data *map);

int			random_move(t_data *map);

bool		check_elements(t_data *map);

void		move_up_ennemi(t_data *map);

void		move_down_ennemi(t_data *map);

void		move_left_ennemi(t_data *map);

void		move_right_ennemi(t_data *map);

bool		parsing_bonus(t_data *map, int fd, char *argv);

bool		launch_minilibx_bonus(t_data *map);

bool		search_player(t_data *map);

bool		get_map_height(int fd, t_data *map);

bool		parse_map_array_bonus(t_data *map);

bool		check_ennemi(t_data *map);

void		find_player_position(t_data *map);

void		fluid_fill(t_data *map, int player_height, int player_width);

bool		check_fluid_fill(t_data *map);

bool		parse_map_borders(t_data *map);

bool		check_elements_bonus(t_data *map);

int			hooks_setup_bonus(int key, t_data *map);

void		define_ennemi_position(t_data *map);

void		move_left_bonus(t_data *map);

void		move_right_bonus(t_data *map);

void		move_up_bonus(t_data *map);

void		move_down_bonus(t_data *map);

void		free_2d_array(void **NULL_TERMINATED);

void		destroy_mlx(t_data *map);

void		print_images2(t_data *map, int i, int j);

bool		parse_map_array(t_data *map);

void		clear_images(t_data *map);

#endif