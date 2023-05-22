/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:59:03 by obouhlel          #+#    #+#             */
/*   Updated: 2023/05/22 14:33:20 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	check_extension(char *map)
{
	int	len;

	len = 0;
	len = ft_strlen(map);
	if (len < 5)
		return (EXIT_FAILURE);
	if (map[--len] != 'b')
		return (EXIT_FAILURE);
	if (map[--len] != 'u')
		return (EXIT_FAILURE);
	if (map[--len] != 'c')
		return (EXIT_FAILURE);
	if (map[--len] != '.')
		return (EXIT_FAILURE);
	if (map[--len] == '.')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_directory_file(char *map)
{
	int		len;
	char	*dir_map;
	int		dir_fd;

	dir_map = ft_strdup(map);
	if (!dir_map)
		return (EXIT_FAILURE);
	len = ft_strlen(dir_map);
	while (--len >= 0 && dir_map[len] != '/')
		dir_map[len] = 0;
	if (dir_map[0] == 0)
		return (free(dir_map), EXIT_SUCCESS);
	dir_fd = open(dir_map, O_DIRECTORY);
	if (dir_fd == -1)
	{
		printf("Error\n%s is a directories\n", map);
		free(dir_map);
		return (EXIT_FAILURE);
	}
	return (free(dir_map), EXIT_SUCCESS);
}

static int	check_file(char *map)
{
	int	fd;

	fd = -1;
	if (check_extension(map))
	{
		printf("%s ", map);
		printf("Error\nis a bad file name\n");
		return (-1);
	}
	if (check_directory_file(map))
		return (-1);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n%s is not readable or doesn't exist\n", map);
		return (-1);
	}
	return (fd);
}

int	launch(char *map, t_data *data)
{
	int	fd;

	fd = check_file(map);
	if (fd == -1)
		return (EXIT_FAILURE);
	if (parse_map(fd, data) == 0)
		return (close (fd), EXIT_FAILURE);
	ft_close(&fd);
	if (check_map(data) == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
