/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ko-mahon <ko-mahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:19:26 by ko-mahon          #+#    #+#             */
/*   Updated: 2025/08/01 10:27:10 by ko-mahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean_exit(t_map *map, char *msg, int is_error)
{
	if (map)
	{
		free_images(map);
		if (map->win)
			mlx_destroy_window(map->mlx, map->win);
		if (map->mlx)
		{
			mlx_destroy_display(map->mlx);
			free(map->mlx);
		}
		free_grid(map->grid);
	}
	if (is_error && msg)
		ft_putstr_fd(msg, 2);
	exit(is_error);
}
