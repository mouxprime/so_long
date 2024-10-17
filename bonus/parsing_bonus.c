/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:48:38 by mianni            #+#    #+#             */
/*   Updated: 2024/09/16 15:52:38 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_utils/so_long.h"

bool	parsing_bonus(t_data *map, int fd, char *argv)
{
	get_map_height(fd, map);
	map->array = setup_map_array(map, fd, argv);
	if (!map->array)
		return (close_and_clear(map->array, fd, map), false);
	else if (parse_map_array_bonus(map) == false)
		return (close_and_clear(map->array, fd, map), false);
	else if (parse_map_borders(map) == false)
		return (write(2, "Error, incorrect map.\n", 22),
			close_and_clear(map->array, fd, map), false);
	if (check_elements_bonus(map) == false)
		return (close_and_clear(map->array, fd, map), false);
	else if (check_ennemi(map) == false)
		return (close_and_clear(map->array, fd, map), false);
	find_player_position(map);
	fluid_fill(map, map->player_height, map->player_width);
	if (check_fluid_fill(map) == false)
		return (write(2, "Error, no valid path.\n", 22),
			close_and_clear(map->array, fd, map), false);
	return (true);
}

bool	check_elements_bonus(t_data *map)
{
	if (map->players == 0)
		return (write(2, "Error, no player.\n", 18), false);
	else if (map->players > 1)
		return (write(2, "Error, too much players.\n", 25), false);
	else if (map->collectibles < 1)
		return (write(2, "Error, no collectibles.\n", 24), false);
	else if (map->exit < 1)
		return (write(2, "Error, no exit.\n", 16), false);
	else if (map->exit > 1)
		return (write(2, "Error, too many exits.\n", 23), false);
	return (true);
}

bool	parse_map_array_bonus(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->array[i])
	{
		j = 0;
		while (map->array[i][j])
		{
			if (map->array[i][j] == 'E')
				map->exit++;
			else if (map->array[i][j] == 'C')
				map->collectibles++;
			else if (map->array[i][j] == 'P')
				map->players++;
			else if (map->array[i][j] != '0' && map->array[i][j] != '1'
				&& map->array[i][j] != '\n' && map->array[i][j] != 'X'
				&& map->array[i][j])
				return (write(2, "Error, invalid character.\n", 26), false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_ennemi(t_data *map)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (map->array[i])
	{
		j = 0;
		while (map->array[i][j])
		{
			if (map->array[i][j] == 'X')
				x++;
			j++;
		}
		i++;
	}
	if (x < 1)
		return (write(2, "Error, no ennemis.\n", 19), false);
	if (x > 1)
		return (write(2, "Error, too much ennemis.\n", 25), false);
	else
		return (true);
}
