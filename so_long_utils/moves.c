/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:07:45 by mianni            #+#    #+#             */
/*   Updated: 2024/09/16 17:39:09 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *map)
{
	if (map->array[map->player_height][map->player_width] != 'E')
		map->array[map->player_height][map->player_width] = '0';
	map->player_height--;
	check_player_position(map);
	if (map->array[map->player_height][map->player_width] != 'E')
		map->array[map->player_height][map->player_width] = 'P';
	ft_printf("Moves = %d\n", map->move++);
}

void	move_left(t_data *map)
{
	if (map->array[map->player_height][map->player_width] != 'E')
		map->array[map->player_height][map->player_width] = '0';
	map->player_width--;
	check_player_position(map);
	if (map->array[map->player_height][map->player_width] != 'E')
		map->array[map->player_height][map->player_width] = 'P';
	ft_printf("Moves = %d\n", map->move++);
}

void	move_down(t_data *map)
{
	if (map->array[map->player_height][map->player_width] != 'E')
		map->array[map->player_height][map->player_width] = '0';
	map->player_height++;
	check_player_position(map);
	if (map->array[map->player_height][map->player_width] != 'E')
		map->array[map->player_height][map->player_width] = 'P';
	ft_printf("Moves = %d\n", map->move++);
}

void	move_right(t_data *map)
{
	if (map->array[map->player_height][map->player_width] != 'E')
		map->array[map->player_height][map->player_width] = '0';
	map->player_width++;
	check_player_position(map);
	if (map->array[map->player_height][map->player_width] != 'E')
		map->array[map->player_height][map->player_width] = 'P';
	ft_printf("Moves = %d\n", map->move++);
}
