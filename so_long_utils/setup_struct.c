/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:54:56 by mianni            #+#    #+#             */
/*   Updated: 2024/09/16 15:48:50 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*start_struct(void)
{
	t_data	*map;

	map = malloc(1 * sizeof(t_data));
	if (!map)
		return (NULL);
	setup_data(map);
	return (map);
}

void	setup_data(t_data *map)
{
	map->collectibles = 0;
	map->exit = 0;
	map->height = 0;
	map->mlx_ptr = NULL;
	map->players = 0;
	map->array = NULL;
	map->collectible = NULL;
	map->floor = NULL;
	map->ennemi = NULL;
	map->sprite = NULL;
	map->sprite_r = NULL;
	map->exit_c = NULL;
	map->exit_o = NULL;
	map->wall = NULL;
	map->width = 0;
	map->win_ptr = NULL;
	map->move = 0;
	map->ennemi_height = 0;
	map->ennemi_width = 0;
	map->move_right = 0;
}
