/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:13:16 by mianni            #+#    #+#             */
/*   Updated: 2024/09/16 17:03:49 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	launch_minilibx(t_data *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		return (false);
	map->win_ptr = mlx_new_window(map->mlx_ptr, (map->width - 1) * 60,
			map->height * 60, "so_long");
	if (!map->win_ptr)
		return (free(map->mlx_ptr), false);
	setup_images(map);
	print_images(map, 0, 0);
	mlx_hook(map->win_ptr, DestroyNotify, StructureNotifyMask, destroy_window,
		map);
	mlx_key_hook(map->win_ptr, hooks_setup, map);
	mlx_loop(map->mlx_ptr);
	return (true);
}

int	hooks_setup(int key, t_data *map)
{
	if (key == 65307)
		destroy_window(map);
	if ((key == 119 || key == 65362) && map->array[map->player_height
			- 1][map->player_width] != '1')
		move_up(map);
	if ((key == 97 || key == 65361)
		&& map->array[map->player_height][map->player_width - 1] != '1')
		move_left(map);
	if ((key == 115 || key == 65364) && map->array[map->player_height
			+ 1][map->player_width] != '1')
		move_down(map);
	if ((key == 100 || key == 65363)
		&& map->array[map->player_height][map->player_width + 1] != '1')
		move_right(map);
	print_images(map, 0, 0);
	return (1);
}

void	setup_images(t_data *map)
{
	int	i;
	int	j;

	map->floor = mlx_xpm_file_to_image(map->mlx_ptr, FLOOR, &i, &j);
	map->collectible = mlx_xpm_file_to_image(map->mlx_ptr, COLLECTIBLE, &i, &j);
	map->ennemi = mlx_xpm_file_to_image(map->mlx_ptr, ENNEMI, &i, &j);
	map->exit_c = mlx_xpm_file_to_image(map->mlx_ptr, EXIT_C, &i, &j);
	map->exit_o = mlx_xpm_file_to_image(map->mlx_ptr, EXIT_O, &i, &j);
	map->sprite = mlx_xpm_file_to_image(map->mlx_ptr, PLAYER, &i, &j);
	map->wall = mlx_xpm_file_to_image(map->mlx_ptr, WALL, &i, &j);
	map->sprite_r = mlx_xpm_file_to_image(map->mlx_ptr, PLAYER_R, &i, &j);
}

void	print_images(t_data *map, int i, int j)
{
	while (map->array[i])
	{
		j = 0;
		while (map->array[i][j])
		{	
			print_images2(map, i, j);
			j++;
		}
		i++;
	}
}

void	print_images2(t_data *map, int i, int j)
{
	if (map->array[i][j] == '0')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor,
			j * 60, i * 60);
	if (map->array[i][j] == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall, j
			* 60, i * 60);
	if (map->array[i][j] == 'P' && map->move_right == 0)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->sprite, j * 60,
			i * 60);
	if (map->array[i][j] == 'P' && map->move_right == 1)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->sprite_r, j
			* 60, i * 60);
	if (map->array[i][j] == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->collectible, j
			* 60, i * 60);
	if (map->array[i][j] == 'X')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->ennemi, j * 60,
			i * 60);
	if (map->array[i][j] == 'E' && map->collectibles != 0)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->exit_c, j * 60,
			i * 60);
	if (map->array[i][j] == 'E' && map->collectibles == 0)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->exit_o, j * 60,
			i * 60);
}
