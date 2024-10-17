/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:37:49 by mianni            #+#    #+#             */
/*   Updated: 2024/09/16 15:48:33 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window(t_data *map)
{
	int	i;

	i = 0;
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	exit(0);
	free(map);
	return (0);
}

void	check_player_position(t_data *map)
{
	if (map->array[map->player_height][map->player_width] == 'C')
		map->collectibles--;
	if (map->array[map->player_height][map->player_width] == 'E'
		&& map->collectibles != 0)
		return ;
	if (map->array[map->player_height][map->player_width] == 'E'
		&& map->collectibles == 0)
	{
		map->players = 2;
		close_and_clear(map->array, map->player_height, map);
	}
	if (map->collectible == 0)
		map->exit_c = &map->exit_o;
}
