/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:43:43 by mianni            #+#    #+#             */
/*   Updated: 2024/09/16 17:44:48 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_all_width(t_data *map)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->height && map->array)
	{
		if (ft_strlen(map->array[i]) != map->width && map->array[i][map->width
			- 1] != '\0')
			return (false);
		i++;
	}
	return (true);
}

void	free_2d_array(void **NULL_TERMINATED)
{
	int	i;

	i = -1;
	while (NULL_TERMINATED[++i] != NULL)
	{
		free(NULL_TERMINATED[i]);
	}
	free(NULL_TERMINATED);
}

void	destroy_mlx(t_data *map)
{
	if (map->mlx_ptr && map->win_ptr)
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	map->win_ptr = NULL;
	if (map->mlx_ptr)
		mlx_destroy_display(map->mlx_ptr);
}

void	close_and_clear(char **map_array, int fd, t_data *map)
{
	size_t	i;

	if (map->players == 2)
		write(1, "\033[1;32mSUCCESS, WELL PLAYED\033[0m\n", 32);
	clear_images(map);
	destroy_mlx(map);
	i = 0;
	close(fd);
	(void)map_array;
	if (map->array)
	{
		while (map->array[i] && i < map->height + 1)
		{
			free(map->array[i]);
			i++;
		}
	}
	free(map->array);
	if (map->mlx_ptr)
	{
		free(map->mlx_ptr);
		map->mlx_ptr = NULL;
	}
	free(map);
	exit(10);
}

void	clear_images(t_data *map)
{
	if (map->floor)
		mlx_destroy_image(map->mlx_ptr, map->floor);
	if (map->collectible)
		mlx_destroy_image(map->mlx_ptr, map->collectible);
	if (map->exit_c)
		mlx_destroy_image(map->mlx_ptr, map->exit_c);
	if (map->exit_o)
		mlx_destroy_image(map->mlx_ptr, map->exit_o);
	if (map->sprite)
		mlx_destroy_image(map->mlx_ptr, map->sprite);
	if (map->sprite_r)
		mlx_destroy_image(map->mlx_ptr, map->sprite_r);
	if (map->wall)
		mlx_destroy_image(map->mlx_ptr, map->wall);
	if (map->ennemi)
		mlx_destroy_image(map->mlx_ptr, map->ennemi);
}
