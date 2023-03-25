
#include "../srcs/cub.h"

char **handle_first_line(char **file, char *line)
{
	file = malloc(sizeof(char *) * 2);
	if (file == NULL)
		return (NULL);
	file[0] = (line);
	file[1] = NULL;
	return (file);
}

int main(void)
{
	char	**file;

	file = NULL;
	file = handle_first_line(file, "test");
	if (file == NULL)
		printf("ERROR\n");
	else
		printf("%s\n", file[0]);
	return (0);
}