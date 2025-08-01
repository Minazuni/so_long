/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ko-mahon <ko-mahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:40:53 by ko-mahon          #+#    #+#             */
/*   Updated: 2025/07/31 13:59:08 by ko-mahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/Gnl/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

/* Structure principale du jeu */
typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	int		player_x;
	int		player_y;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	int		img_w;
	int		img_h;
	int		move_count;
}			t_map;

/* Parsing */
int			check_extension(char *filename);
int			sub_check_content(t_map *map, int x, int y);
int			check_content(t_map *map);
char		**read_map(char *filename, t_map *map);
int			is_rectangular(char **map);
int			is_walled(char **map);
int			is_walled_last_line(char **map);
char		*append_line(char *joined, char *line);
void		free_images(t_map *map);
void		free_grid(char **grid);
void		display_map(t_map *map);
int			handle_key(int keycode, void *param);
void		find_player_position(t_map *map);
char		**dup_grid(char **grid, int height);
int			is_map_solvable(char **grid);
void		flood_fill(char **grid, int x, int y);
void		fill(char **grid, int x, int y);
int			end_game(t_map *map);
int			clean_exit(t_map *map, char *msg, int is_error);
void		free_string_array(char **arr);
int			is_rectangular(char **grid);
char		*read_and_join_lines(int fd);
int			init_and_validate_map(t_map *map, char *filename);
int			load_images(t_map *map);
int			ft_countword(const char *str, char sep);
int			handle_close(void *param);

#endif
