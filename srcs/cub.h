#ifndef CUB_FILE
#define CUB_FILE
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>


typedef struct s_line
{
	char *value;
	int	line;
	struct s_line	*next;
}	t_line;

// PARSING
int		parse_map(int fd);
char	**save_line(int position, char *map, char **file);
int		check_element(char **file);
char	**iterate_on_file(char *buf, int fd, char *map, char **file);
char	**read_file(char **file, char *map, int fd);
int		parse_map(int fd);

// UTILS
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char 	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
t_line	*create_node(int line, char *value);
void    add_last(t_line **lst, t_line *new_node);
char	**ft_split(char const *s, char c);
int 	ft_strcmp(const char *s1, const char *s2);

#endif