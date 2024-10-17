/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:29:49 by mianni            #+#    #+#             */
/*   Updated: 2024/09/16 17:34:51 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int		main(void)
// {
// 	void	*minilibx_ptr;
// 	void	*window_ptr;

// 	minilibx_ptr = mlx_init();
// 	if (!minilibx_ptr)
// 		return (1);
// 	window_ptr = mlx_new_window(minilibx_ptr, 2000, 1600, "so_long");
// 	if (!window_ptr)
// 		return (free(minilibx_ptr), 1);
// 	mlx_loop(minilibx_ptr);

// 	mlx_destroy_window(minilibx_ptr, window_ptr);
// 	mlx_destroy_display(minilibx_ptr);
// 	free (minilibx_ptr);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	int		fd;
	t_data	*map;

	if (argc != 2)
		return (write(2, "Error,  arguments.\n", 28), 1);
	fd = open(argv[1], O_RDONLY);
	if (check_input_file(argv, fd) == false)
		return (0);
	map = start_struct();
	if (!map)
		return (0);
	if (parsing(map, fd, argv[1]) == false)
		return (0);
	map->players = 2;
	free_2d_array((void **)map->array);
	map->array = setup_map_array(map, fd, argv[1]);
	launch_minilibx(map);
	mlx_loop(map->mlx_ptr);
	close_and_clear(map->array, fd, map);
	return (1);
}

// so_long fini & bonus aussi, reste l'affichage du compteur de moves
//, et la prise en compte du \n en debit de map

// verifier taille de l'image et chmod.