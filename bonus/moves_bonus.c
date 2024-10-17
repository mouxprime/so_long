/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:05:29 by mianni            #+#    #+#             */
/*   Updated: 2024/09/15 21:49:30 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_utils/so_long.h"

void	move_left_bonus(t_data *map)
{
	if (map->array[map->player_height][map->player_width] != 'E')
		map->array[map->player_height][map->player_width] = '0';
	map->player_width--;
	check_player_position(map);
	if (map->array[map->player_height][map->player_width] != 'E')
		map->array[map->player_height][map->player_width] = 'P';
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	map->move_right = 0;
	map->move++;
}

void	move_right_bonus(t_data *map)
{
	if (map->array[map->player_height][map->player_width] != 'E')
		map->array[map->player_height][map->player_width] = '0';
	map->player_width++;
	check_player_position(map);
	if (map->array[map->player_height][map->player_width] != 'E')
		map->array[map->player_height][map->player_width] = 'P';
	map->move_right = 1;
	map->move++;
}

void	move_up_bonus(t_data *map)
{
	if (map->array[map->player_height][map->player_width] != 'E')
		map->array[map->player_height][map->player_width] = '0';
	map->player_height--;
	check_player_position(map);
	if (map->array[map->player_height][map->player_width] != 'E')
		map->array[map->player_height][map->player_width] = 'P';
	map->move++;
}

void	move_down_bonus(t_data *map)
{
	if (map->array[map->player_height][map->player_width] != 'E')
		map->array[map->player_height][map->player_width] = '0';
	map->player_height++;
	check_player_position(map);
	if (map->array[map->player_height][map->player_width] != 'E')
		map->array[map->player_height][map->player_width] = 'P';
	map->move++;
}
