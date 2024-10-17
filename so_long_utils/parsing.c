/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:22:17 by mianni            #+#    #+#             */
/*   Updated: 2024/09/16 17:46:28 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	get_map_height(int fd, t_data *map)
{
	int		height;
	char	temp[1];
	int		width;

	height = 0;
	width = 0;
	while (read(fd, temp, 1) > 0)
	{
		if (temp[0] == '\n' || temp[0] == '\0')
			height++;
		if (temp[0] != '\n' && height == 0)
			width++;
	}
	map->height = height + 1;
	map->width = width + 1;
	if (map->height < 3 || map->width < 3)
		return (ft_putendl_fd("Error,\nmap is too small", 2)
			, false);
	return (close(fd), true);
}

char	**setup_map_array(t_data *map, int fd, char *argv)
{
	size_t	i;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map->array = malloc((map->height + 1) * sizeof(char *));
	if (!map->array)
		return (NULL);
	map->array[map->height] = NULL;
	ft_bzero(map->array, map->height + 1);
	while (i < map->height && map->array)
	{
		map->array[i] = get_next_line(fd);
		if (!map->array[i])
			return (ft_putendl_fd("Error,\nempty line at end of file.", 2)
				, close_and_clear(map->array, fd, map), NULL);
		if (map->array[i][0] == '\n' && map->array[i])
			return (map->array[i + 1] = NULL, free_2d_array((void **)map->array)
				, ft_putendl_fd("Error,\ninvalid map.", 2), NULL);
		i++;
	}
	if (check_all_width(map) == false)
		return (ft_putendl_fd("Error,\nmap is not rectangular.", 2), NULL);
	return (close(fd), map->array);
}

bool	parse_map_array(t_data *map)
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
				&& map->array[i][j] != '\n' && map->array[i][j])
				return (ft_putendl_fd("Error, invalid character.", 2), false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	parse_map_borders(t_data *map)
{
	size_t	j;

	j = 0;
	while (j < map->width - 1)
	{
		if (map->array[0][j] != '1')
			return (false);
		if (map->array[map->height - 1][j] != '1')
			return (false);
		j++;
	}
	j = 0;
	while (j < map->height - 1)
	{
		if (map->array[j][0] != '1' && map->array[j][map->width - 1] != '1')
			return (false);
		j++;
	}
	return (true);
}

void	fluid_fill(t_data *map, int player_height, int player_width)
{
	size_t	i;
	size_t	j;

	i = player_height;
	j = player_width;
	if (i < 0 || j < 0 || j > map->width - 1 || i > map->height - 1
		|| map->array[i][j] == '1' || map->array[i][j] == 'Z')
		return ;
	else
	{
		map->array[i][j] = 'Z';
		if (i < map->height - 1)
			fluid_fill(map, i + 1, j);
		if (j < map->width - 1)
			fluid_fill(map, i, j + 1);
		if (i > 1)
			fluid_fill(map, i - 1, j);
		if (j > 1)
			fluid_fill(map, i, j - 1);
	}
}
