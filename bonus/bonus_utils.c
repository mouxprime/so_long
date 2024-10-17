/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:20:29 by mianni            #+#    #+#             */
/*   Updated: 2024/09/16 15:51:41 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_utils/so_long.h"

int	random_move(t_data *map)
{
	int	random;
	int	move;

	move = 0;
	while (move < 1)
	{
		define_ennemi_position(map);
		random = rand() % 4;
		if (random == 0 && map->array[map->ennemi_height
				- 1][map->ennemi_width] != '1')
			return (move_up_ennemi(map), move++);
		else if (random == 1 && map->array[map->ennemi_height][map->ennemi_width
			- 1] != '1')
			return (move_left_ennemi(map), move++);
		else if (random == 2 && map->array[map->ennemi_height
				+ 1][map->ennemi_width] != '1')
			return (move_down_ennemi(map), move++);
		else if (random == 3 && map->array[map->ennemi_height][map->ennemi_width
			+ 1] != '1')
			return (move_right_ennemi(map), move++);
	}
	return (0);
}
