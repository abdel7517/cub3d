/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:07:36 by abchaban          #+#    #+#             */
/*   Updated: 2023/03/27 00:55:52 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_extension(char *map)
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

int check_file(char *map)
{
	int	fd;

	fd = -1;
	if (check_extension(map) == 0)
	{
		printf("%s ", map);
		printf("is a bad file name\n");
		return (-1);
	}
	fd = open(map, O_DIRECTORY);
	if (fd > 0)
	{
		printf("%s ", map);
		printf("is a directories\n");
		close(fd);
		return (-1);
	}	
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		printf("%s ", map);
		printf("is not readable\n");
		return (-1);
	}
	return (fd);
}

int launch(char *map, t_game *data)
{
	int	fd;

	(void)data;
	fd = check_file(map);
	if (fd == -1)
		return (0);
	if (parse_map(fd, data) == 0)
 		return (0);
	return (1);
}

void init_game(t_game *data)
{
	data->data = NULL;
	data->file = NULL;
	data->map = NULL;
	data->path = NULL;
}

int main(int argc, char **argv)
{
	t_game	data;

	init_game(&data);
	if (argc != 2)
	{
		printf("Invalids numbers of arguments\n");
		return (0);
	}
	if (launch(argv[1], &data) == 0)
	{
		printf("ERROR\n");
		return (0);
	}
}
