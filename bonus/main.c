/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:44:28 by mianni            #+#    #+#             */
/*   Updated: 2024/09/16 16:14:00 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_utils/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_data	*map;

	if (argc != 2)
		return (ft_putendl_fd("Error,\nnon-valid arguments.", 2), 1);
	fd = open(argv[1], O_RDONLY);
	if (check_input_file(argv, fd) == false)
		return (0);
	map = start_struct();
	if (!map)
		return (0);
	if (parsing_bonus(map, fd, argv[1]) == false)
		return (0);
	map->players = 2;
	free_2d_array((void **)map->array);
	map->array = setup_map_array(map, fd, argv[1]);
	launch_minilibx_bonus(map);
	mlx_loop(map->mlx_ptr);
	close_and_clear(map->array, fd, map);
	return (1);
}
