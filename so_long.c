/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ko-mahon <ko-mahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:36:52 by ko-mahon          #+#    #+#             */
/*   Updated: 2025/07/31 13:07:13 by ko-mahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_tile(t_map *map, int x, int y)
{
	int	px;
	int	py;

	px = x * map->img_w;
	py = y * map->img_h;
	if (map->grid[y][x] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->img_wall, px, py);
	else if (map->grid[y][x] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img_floor, px, py);
	else if (map->grid[y][x] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, px, py);
	else if (map->grid[y][x] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->img_collectible, px,
			py);
	else if (map->grid[y][x] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->img_exit, px, py);
}

void	display_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			display_tile(map, x, y);
			x++;
		}
		y++;
	}
}

int	handle_close(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	clean_exit(map, NULL, 0);
	return (0);
}
