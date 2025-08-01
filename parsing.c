/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ko-mahon <ko-mahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:00:15 by ko-mahon          #+#    #+#             */
/*   Updated: 2025/07/22 15:43:14 by ko-mahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sub_check_content(t_map *map, int x, int y)
{
	while (map->grid[y][x])
	{
		if (map->grid[y][x] == 'P')
		{
			map->player_count += 1;
			map->player_x = x;
			map->player_y = y;
		}
		else if (map->grid[y][x] == 'E')
			map->exit_count += 1;
		else if (map->grid[y][x] == 'C')
			map->collectible_count += 1;
		else if (map->grid[y][x] != '1' && map->grid[y][x] != '0')
			return (0);
		x++;
	}
	return (1);
}

int	check_content(t_map *map)
{
	int	y;

	map->player_count = 0;
	map->exit_count = 0;
	map->collectible_count = 0;
	y = 0;
	while (map->grid[y])
	{
		if (!sub_check_content(map, 0, y))
			return (0);
		y++;
	}
	if (map->player_count != 1 || map->exit_count != 1
		|| map->collectible_count < 1)
		return (0);
	map->height = y;
	map->width = ft_strlen(map->grid[0]);
	return (1);
}

void	find_player_position(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

char	**dup_grid(char **grid, int height)
{
	char	**new_grid;
	int		i;

	new_grid = malloc(sizeof(char *) * (height + 1));
	if (!new_grid)
		return (NULL);
	i = 0;
	while (i < height)
	{
		new_grid[i] = ft_strdup(grid[i]);
		if (!new_grid[i])
		{
			while (--i >= 0)
				free(new_grid[i]);
			free(new_grid);
			return (NULL);
		}
		i++;
	}
	new_grid[i] = NULL;
	return (new_grid);
}

int	is_map_solvable(char **grid)
{
	int	y;
	int	x;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
