/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemi_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:32:52 by mianni            #+#    #+#             */
/*   Updated: 2024/09/16 15:51:53 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_utils/so_long.h"

void	move_up_ennemi(t_data *map)
{
	if (map->array[map->ennemi_height][map->ennemi_width] != 'E'
		&& map->array[map->ennemi_height][map->ennemi_width] != 'C')
		map->array[map->ennemi_height][map->ennemi_width] = '0';
	map->ennemi_height--;
	if (map->array[map->ennemi_height][map->ennemi_width] != 'E'
		&& map->array[map->ennemi_height][map->ennemi_width] != 'C')
		map->array[map->ennemi_height][map->ennemi_width] = 'X';
}

void	move_left_ennemi(t_data *map)
{
	if (map->array[map->ennemi_height][map->ennemi_width] != 'E'
		&& map->array[map->ennemi_height][map->ennemi_width] != 'C')
		map->array[map->ennemi_height][map->ennemi_width] = '0';
	map->ennemi_width--;
	if (map->array[map->ennemi_height][map->ennemi_width] != 'E'
		&& map->array[map->ennemi_height][map->ennemi_width] != 'C')
		map->array[map->ennemi_height][map->ennemi_width] = 'X';
}

void	move_down_ennemi(t_data *map)
{
	if (map->array[map->ennemi_height][map->ennemi_width] != 'E'
		&& map->array[map->ennemi_height][map->ennemi_width] != 'C')
		map->array[map->ennemi_height][map->ennemi_width] = '0';
	map->ennemi_height++;
	if (map->array[map->ennemi_height][map->ennemi_width] != 'E'
		&& map->array[map->ennemi_height][map->ennemi_width] != 'C')
		map->array[map->ennemi_height][map->ennemi_width] = 'X';
}

void	move_right_ennemi(t_data *map)
{
	if (map->array[map->ennemi_height][map->ennemi_width] != 'E'
		&& map->array[map->ennemi_height][map->ennemi_width] != 'C')
		map->array[map->ennemi_height][map->ennemi_width] = '0';
	map->ennemi_width++;
	if (map->array[map->ennemi_height][map->ennemi_width] != 'E'
		&& map->array[map->ennemi_height][map->ennemi_width] != 'C')
		map->array[map->ennemi_height][map->ennemi_width] = 'X';
}
