/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:00:25 by abchaban          #+#    #+#             */
/*   Updated: 2023/05/22 13:56:49 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static char	**handle_first_line(char **file, char *line)
{
	file = malloc(sizeof(char *) * 2);
	if (file == NULL)
		return (0);
	file[0] = ft_strdup(line);
	if (file[0] == NULL)
		return (NULL);
	file[1] = NULL;
	return (file);
}

char	**save_line(int position, char *map, char	**file)
{
	static int	last_position = 0;
	char		*line;

	line = ft_substr(map, (last_position * 2), (position - last_position) + 1);
	last_position = position + 1;
	if (line == NULL)
		return (0);
	if (file == NULL)
	{
		file = handle_first_line(file, line);
		return (free(line), file);
	}
	file = cpy_old_file_and_add_new_line(file, line);
	if (file == NULL)
		return (free(file), NULL);
	free(line);
	return (file);
}

char	**iterate_on_file(char *buf, int fd, char *map, char **file)
{
	char	*tmp;
	int		position;

	position = 0;
	while (read(fd, buf, 1) > 0)
	{
		if (buf[0] == '\n')
		{
			file = save_line(position, map, file);
			if (file == NULL)
				return (free_file(file), free(map), NULL);
			continue ;
		}
		tmp = ft_strdup(map);
		if (tmp == NULL)
			return (NULL);
		free(map);
		map = ft_strjoin(tmp, &buf[0]);
		if (map == NULL)
			return (free(tmp), NULL);
		free(tmp);
		position++;
	}
	file = save_line(position, map, file);
	return (free(map), file);
}

char	**read_file(char **file, char *map, int fd)
{
	char	buf[1];

	if (read(fd, buf, 1))
	{
		map = ft_strdup(&buf[0]);
		if (map == NULL)
			return (0);
	}
	file = iterate_on_file(buf, fd, map, file);
	if (file == NULL)
		return (free(map), NULL);
	return (file);
}

int	parse_map(int fd, t_data *data)
{
	char	**file;
	char	*map;

	file = NULL;
	map = NULL;
	file = read_file(file, map, fd);
	if (file == NULL)
		return (0);
	data->file = file;
	if (check_element(data) == 0)
		return (0);
	return (1);
}
