/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:07:36 by abchaban          #+#    #+#             */
/*   Updated: 2023/03/25 14:30:26 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int check_extension(char *map)
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
int check_map(char *map)
{
	int	fd;

	fd = -1;
	if (check_extension(map) == 0)
	{
		printf("%s ", map);
		printf("is a bad file name\n");
		return (0);
	}
	fd = open(map, O_DIRECTORY);
	if (fd > 0)
	{
		printf("%s ", map);
		printf("is a directories\n");
		close(fd);
		return (0);
	}	
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		printf("%s ", map);
		printf("is not readable\n");
		return (0);
	}
	return (fd);
}

int launch(char *map)
{
	int	fd;
	fd = check_map(map);
	if (fd == -1)
		return (0);
	if (parse_map(fd) == 0)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Invalids numbers of arguments\n");
		return (0);
	}
	if (launch(argv[1]) == 0)
	{
		printf("ERROR\n");
		return (0);
	}
}
