/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:59:03 by obouhlel          #+#    #+#             */
/*   Updated: 2023/05/22 12:59:31 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	check_extension(char *map)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	if (len < 5)
		return (0);
	if (map[--len] != 'b')
		return (0);
	if (map[--len] != 'u')
		return (0);
	if (map[--len] != 'c')
		return (0);
	if (map[--len] != '.')
		return (0);
	if (map[--len] == '.')
		return (0);
	return (1);
}

static int	check_file(char *map)
{
	int	fd;

	fd = -1;
	if (check_extension(map) == 0)
	{
		printf("%s ", map);
		printf("Error\nis a bad file name\n");
		return (-1);
	}
	// fd = open(map, O_DIRECTORY);
	// if (fd == -1)
	// {
	// 	printf("Error\n%s is a directories\n", map);
	// 	close(fd);
	// 	return (-1);
	// }
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
	close(fd);
	if (check_map(data) == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
