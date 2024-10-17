/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:41:59 by mianni            #+#    #+#             */
/*   Updated: 2024/09/16 17:01:38 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_position(t_data *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height - 1)
	{
		j = 0;
		while (j < map->width - 1)
		{
			if (map->array[i][j] == 'P')
			{
				map->player_height = i;
				map->player_width = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

bool	check_fluid_fill(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->array[i])
	{
		j = 0;
		while (map->array[i][j])
		{
			if (map->array[i][j] != '1' && map->array[i][j] != 'Z'
				&& map->array[i][j] != '\n' && map->array[i][j]
				&& map->array[i][j] != '0')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	parsing(t_data *map, int fd, char *argv)
{
	get_map_height(fd, map);
	map->array = setup_map_array(map, fd, argv);
	if (!map->array)
		return (close_and_clear(map->array, fd, map), false);
	else if (parse_map_array(map) == false)
		return (close_and_clear(map->array, fd, map), false);
	else if (parse_map_borders(map) == false)
		return (ft_putendl_fd("Error,\n incorrect map.", 2),
			close_and_clear(map->array, fd, map), false);
	if (check_elements(map) == false)
		return (close_and_clear(map->array, fd, map), false);
	find_player_position(map);
	fluid_fill(map, map->player_height, map->player_width);
	if (check_fluid_fill(map) == false)
		return (ft_putendl_fd("Error,\nno valid path.", 2),
			close_and_clear(map->array, fd, map), false);
	return (true);
}

bool	check_elements(t_data *map)
{
	if (map->players == 0)
		return (ft_putendl_fd("Error,\nno player.", 2), false);
	else if (map->players > 1)
		return (ft_putendl_fd("Error,\ntoo much players.", 2), false);
	else if (map->collectibles < 1)
		return (ft_putendl_fd("Error,\nno collectibles.", 2), false);
	else if (map->exit < 1)
		return (ft_putendl_fd("Error,\nno exit.", 2), false);
	else if (map->exit > 1)
		return (ft_putendl_fd("Error,\ntoo many exits.", 2), false);
	return (true);
}

bool	check_input_file(char **argv, int fd)
{
	size_t	i;

	i = ft_strlen(argv[1]);
	if (ft_strnstr(argv[1], ".ber", i) == NULL || fd == -1 || i < 5
		|| argv[1][0] == '.')
		return (write(2, "Error, incorrect input file\n", 28), false);
	return (true);
}
