/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:10:00 by abchaban          #+#    #+#             */
/*   Updated: 2023/05/22 15:37:15 by obouhlel         ###   ########.fr       */
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

// ERROR MESSAGE
# define ERROR_ARG "ERROR\nInvalids numbers of arguments\n"

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
}	t_data;

/************************************PARSING***********************************/
//check_file.c																4/5
int			launch(char *map, t_data *data);

//parsing.c																	5/5
char		**read_file(char **file, char *map, int fd);
char		**save_line(int position, char *map, char **file);
char		**iterate_on_file(char *buf, int fd, char *map, char **file);
int			parse_map(int fd, t_data *data);

//check_item.c																5/5
int			check_element(t_data *data);

//check_texture.c															4/5
int			find_path(char *word);
int			is_id(char *word);

//handle_map.c																5/5
int			check_position_of_map_in_config_file(t_data *data, int i);
int			check_map(t_data *data);

//duplicate_map.c															5/5
void		find_biggest_x_and_y(int *x, int *y, t_data *data);
char		**create_map_cpy(int x, int y, t_data *data);

//check_map_closed.c														5/5
void		flood_fill(t_data *data, int x, int y, char value);
int			check_if_map_is_closed(t_data *data);
int			find_element_on_map(t_data *data);
int			find_starting_position(t_data *data, int *position);
int			find_bad_element_on_map(t_data *data);

/******************************************************************************/

/************************************CASTING***********************************/

int			window_init(t_data *data);

/******************************************************************************/

/*************************************UTILS************************************/
//data.c																	2/5
void		init_data(t_data *data);
void		destroy_data(t_data *data);

//ft_split.c																3/5
char		**ft_split(char const *s, char c);

//utils_1.c																	5/5
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);

//utils_2.c																	5/5
int			ft_strcmp(const char *s1, const char *s2);
char		*create_new_key_value(char *key, char *value);
char		**add_node(char *key, char *value, t_data *data);
char		*get_element(char *key, t_data *data);
void		free_file(char **file);

//utils_3.c																	5/5
void		free_file_in_game(t_data *data);
void		free_data_in_game(t_data *data);
char		**add_line_of_map(char *line, t_data *data);
char		**cpy_old_file_and_add_new_line(char **file, char *line);
int			check_path(t_data *data, char **line_splited, \
						int *path_validated, int i);

//utils_4.c																	3/5
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_close(int *fd);
void		ft_free(void **ptr);

/******************************************************************************/

#endif