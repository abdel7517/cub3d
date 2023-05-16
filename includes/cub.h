/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:10:00 by abchaban          #+#    #+#             */
/*   Updated: 2023/05/16 13:45:34 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../srcs/minilibx-linux/mlx.h"
# include "../srcs/minilibx-linux/mlx_int.h"

# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

// PARSING
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F  4

// WINDOW SIZE
# define WIN_X		1200
# define WIN_Y		700

// EVENTS
enum e_event {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// MASKS
# define NOEVENTMASK		0b0
# define KEYPRESSMASK		0b1
# define KEYRELEASEMASK		0b10

// KEYCODES
# define ESCAPE	65307
# define LEFT	65361
# define RIGHT	65363
# define UP		65362
# define DOWN	65364
# define PGUP	65365
# define PGDOWN	65366

typedef struct s_game
{
	char	**data;
	char	**file;
	char	*path;
	char	**map;
	char	**map_cpy;
	void	*mlx;
	void	*win;
}	t_game;


// PARSING
int			parse_map(int fd, t_game *data);
char		**save_line(int position, char *map, char **file);
int			check_element(t_game *data);
char		**iterate_on_file(char *buf, int fd, char *map, char **file);
char		**read_file(char **file, char *map, int fd);
int			is_id(char *word);
int			check_position_of_map_in_config_file(t_game *data, int i);
int			find_path(char *word);
int			check_map(t_game *data);
char		**create_map_cpy(int x, int y, t_game *data);
void		find_biggest_x_and_y(int *x, int *y, t_game *data);
void		flood_fill(t_game *data, int x, int y, char value);
int			check_if_map_is_closed(t_game *data);
int			find_element_on_map(t_game *data);
int			find_starting_position(t_game *data, int *position);
int			find_bad_element_on_map(t_game *data);

// CASTING
int			window_init(t_game *data);

// UTILS
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
int			ft_strcmp(const char *s1, const char *s2);
void		free_file(char **file);
char		**add_node(char *key, char *value, t_game *data);
void		free_file_in_game(t_game *data);
char		*get_element(char *key, t_game *data);
void		free_data_in_game(t_game *data);
char		**add_line_of_map(char *line, t_game *data);
char		**cpy_old_file_and_add_new_line(char **file, char *line);
int			check_path(t_game *data, char **line_splited,
				int *path_validated, int i);

#endif