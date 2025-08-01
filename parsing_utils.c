/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ko-mahon <ko-mahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:03:28 by ko-mahon          #+#    #+#             */
/*   Updated: 2025/07/31 13:06:15 by ko-mahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

char	*append_line(char *joined, char *line)
{
	char	*tmp;

	tmp = joined;
	joined = ft_strjoin(tmp, line);
	free(tmp);
	return (joined);
}

char	*read_and_join_lines(int fd)
{
	char	*line;
	char	*joined;

	joined = ft_strdup("");
	if (!joined)
		return (NULL);
	while ((line = get_next_line(fd)))
	{
		joined = append_line(joined, line);
		free(line);
		if (!joined)
			return (NULL);
	}
	return (joined);
}

int	is_rectangular(char **grid)
{
	size_t	i;
	size_t	len;

	if (!grid || !grid[0])
		return (0);
	len = ft_strlen(grid[0]);
	i = 0;
	while (grid[i])
	{
		if (ft_strlen(grid[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

char	**read_map(char *filename, t_map *map)
{
	int		fd;
	char	*joined;
	char	**grid;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	joined = read_and_join_lines(fd);
	close(fd);
	if (!joined)
		return (NULL);
	grid = ft_split(joined, '\n');
	free(joined);
	if (!is_rectangular(grid))
	{
		free_string_array(grid);
		return (NULL);
	}
	map->height = ft_countword(joined, '\n');
	map->width = ft_strlen(grid[0]);
	map->grid = grid;
	return (grid);
}




