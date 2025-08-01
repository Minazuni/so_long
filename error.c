/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ko-mahon <ko-mahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:32:54 by ko-mahon          #+#    #+#             */
/*   Updated: 2025/08/01 10:27:14 by ko-mahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(char **grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	free_images(t_map *map)
{
	if (map->img_player)
		mlx_destroy_image(map->mlx, map->img_player);
	if (map->img_collectible)
		mlx_destroy_image(map->mlx, map->img_collectible);
	if (map->img_wall)
		mlx_destroy_image(map->mlx, map->img_wall);
	if (map->img_floor)
		mlx_destroy_image(map->mlx, map->img_floor);
	if (map->img_exit)
		mlx_destroy_image(map->mlx, map->img_exit);
}

void	exit_error(t_map *map, char *msg)
{
	if (map)
	{
		free_grid(map->grid);
		free_images(map);
		if (map->win)
			mlx_destroy_window(map->mlx, map->win);
		if (map->mlx)
			mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}
