/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ko-mahon <ko-mahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:35:20 by ko-mahon          #+#    #+#             */
/*   Updated: 2025/07/31 14:10:50 by ko-mahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_elements(t_map *map, int *player, int *exit, int *collectible)
{
	int	x;
	int	y;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == 'P')
				(*player)++;
			else if (map->grid[y][x] == 'E')
				(*exit)++;
			else if (map->grid[y][x] == 'C')
				(*collectible)++;
			x++;
		}
		y++;
	}
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
