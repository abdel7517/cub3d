#ifndef CUB_FILE
#define CUB_FILE
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F  4

typedef struct s_game
{
	char **data;
	char **file;
	char *path;
}	t_game;

// PARSING
int		parse_map(int fd, t_game *data);
char	**save_line(int position, char *map, char **file);
int		check_element(char **file, t_game *data);
char	**iterate_on_file(char *buf, int fd, char *map, char **file);
char	**read_file(char **file, char *map, int fd);

// UTILS
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char 	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
int 	ft_strcmp(const char *s1, const char *s2);
void	free_file(char **file);
char	**add_node(char *key, char *value, t_game *data);
void	free_file_in_game(t_game *data);
char    *get_element(char *key, t_game *data);

#endif