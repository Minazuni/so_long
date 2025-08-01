/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ko-mahon <ko-mahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:20:45 by ko-mahon          #+#    #+#             */
/*   Updated: 2025/08/01 10:26:32 by ko-mahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move(t_map *map, int new_x, int new_y)
{
	if (new_y < 0 || new_y >= map->height || new_x < 0 || new_x >= map->width)
		return (0);
	if (map->grid[new_y][new_x] == '1')
		return (0);
	return (1);
}

int	process_movement(t_map *map, int new_x, int new_y)
{
	char	next_cell;

	next_cell = map->grid[new_y][new_x];
	if (next_cell == 'C')
		map->collectible_count--;
	if (next_cell == 'E' && map->collectible_count == 0)
	{
		map->move_count++;
		clean_exit(map, NULL, 0);
	}
	else if (next_cell == 'E')
		return (0);
	map->grid[map->player_y][map->player_x] = '0';
	map->grid[new_y][new_x] = 'P';
	map->player_x = new_x;
	map->player_y = new_y;
	map->move_count++;
	ft_printf("Move count: %d\n", map->move_count);
	display_map(map);
	return (1);
}

int	handle_key(int keycode, void *param)
{
	t_map	*map;
	int		new_x;
	int		new_y;

	map = (t_map *)param;
	new_x = map->player_x;
	new_y = map->player_y;
	if (keycode == 119)
		new_y -= 1;
	else if (keycode == 115)
		new_y += 1;
	else if (keycode == 97)
		new_x -= 1;
	else if (keycode == 100)
		new_x += 1;
	else if (keycode == 65307)
		clean_exit(map, NULL, 0);
	else
		return (0);
	if (!can_move(map, new_x, new_y))
		return (0);
	return (process_movement(map, new_x, new_y));
}
