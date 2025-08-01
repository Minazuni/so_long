/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ko-mahon <ko-mahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:07:28 by ko-mahon          #+#    #+#             */
/*   Updated: 2025/08/01 10:37:36 by ko-mahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_and_validate_map(t_map *map, char *filename)
{
	char	**map_copy;

	map->grid = read_map(filename, map);
	if (!is_rectangular(map->grid))
		return (clean_exit(map, "Error: Map is not rectangular\n", 1));
	if (!is_walled(map->grid))
		return (clean_exit(map, "Error: Map not surrounded by walls\n", 1));
	if (!check_content(map))
		return (clean_exit(map, "Error: Invalid map content\n", 1));
	find_player_position(map);
	map_copy = dup_grid(map->grid, map->height);
	if (!map_copy)
		return (clean_exit(map, "Memory error (dup_grid)\n", 1));
	flood_fill(map_copy, map->player_x, map->player_y);
	if (!is_map_solvable(map_copy))
		return (free_grid(map_copy), clean_exit(map, "Unsolvable map\n", 1));
	free_grid(map_copy);
	return (0);
}

int	load_images(t_map *map)
{
	int	w;
	int	h;

	map->img_player = mlx_xpm_file_to_image(map->mlx, "sprite/ryuk.xpm", &w,
			&h);
	map->img_collectible = mlx_xpm_file_to_image(map->mlx, "sprite/pomme.xpm",
			&w, &h);
	map->img_wall = mlx_xpm_file_to_image(map->mlx, "sprite/mur.xpm", &w, &h);
	map->img_floor = mlx_xpm_file_to_image(map->mlx, "sprite/sol.xpm", &w, &h);
	map->img_exit = mlx_xpm_file_to_image(map->mlx, "sprite/exit.xpm", &w, &h);
	if (!map->img_player || !map->img_collectible || !map->img_wall
		|| !map->img_floor || !map->img_exit)
		return (clean_exit(map, "Failed to load images\n", 1));
	return (0);
}

int	init_game(t_map *map, char *filename)
{
	if (!check_extension(filename))
		return (ft_putstr_fd("Invalid file extension. Must be .ber\n", 2), 1);
	ft_bzero(map, sizeof(t_map));
	map->move_count = 0;
	map->img_w = 64;
	map->img_h = 64;
	if (init_and_validate_map(map, filename))
		return (1);
	map->mlx = mlx_init();
	if (!map->mlx)
		return (clean_exit(map, "MLX init failed\n", 1));
	map->win = mlx_new_window(map->mlx, map->width * map->img_w, map->height
			* map->img_h, "so_long");
	if (!map->win)
		return (clean_exit(map, "Window creation failed\n", 1));
	if (load_images(map))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (ft_putstr_fd("Error\nUsage: ./so_long maps/map.ber\n", 2), 1);
	if (init_game(&map, argv[1]))
		return (1);
	display_map(&map);
	mlx_key_hook(map.win, handle_key, &map);
	mlx_hook(map.win, 17, 0, handle_close, &map);
	mlx_loop(map.mlx);
	return (0);
}
