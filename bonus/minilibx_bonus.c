/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:59:42 by mianni            #+#    #+#             */
/*   Updated: 2024/09/16 17:14:51 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_utils/so_long.h"

bool	launch_minilibx_bonus(t_data *map)
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
	mlx_key_hook(map->win_ptr, hooks_setup_bonus, map);
	mlx_loop(map->mlx_ptr);
	return (true);
}

int	hooks_setup_bonus(int key, t_data *map)
{
	char	str[50];

	if (search_player(map) == false)
		close_and_clear(map->array, 3, map);
	if (key == 65307)
		destroy_window(map);
	if ((key == 119 || key == 65362) && map->array[map->player_height
			- 1][map->player_width] != '1')
		move_up_bonus(map);
	if ((key == 97 || key == 65361)
		&& map->array[map->player_height][map->player_width - 1] != '1')
		move_left_bonus(map);
	if ((key == 115 || key == 65364) && map->array[map->player_height
			+ 1][map->player_width] != '1')
		move_down_bonus(map);
	if ((key == 100 || key == 65363)
		&& map->array[map->player_height][map->player_width + 1] != '1')
		move_right_bonus(map);
	print_images(map, 0, 0);
	snprintf(str, sizeof(str), "Moves = %zu", map->move);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1050, 50, 0xFFFFF, str);
	random_move(map);
	print_images(map, 0, 0);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1050, 50, 0xFFFFF, str);
	return (1);
}

bool	search_player(t_data *map)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	print_images(map, 0, 0);
	while (map->array[i])
	{
		j = 0;
		while (map->array[i][j])
		{
			if (map->array[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (p == 0 && map->array[map->player_height][map->player_width] != 'E')
		return (write(1, "\033[1;31mYOU DIED\033[0m\n", 20), (map->players = 1),
			false);
	else
		return ((map->players = 2), true);
}

void	define_ennemi_position(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->array[i])
	{
		j = 0;
		while (map->array[i][j])
		{
			if (map->array[i][j] == 'X')
			{
				map->ennemi_height = i;
				map->ennemi_width = j;
			}
			j++;
		}
		i++;
	}
}
