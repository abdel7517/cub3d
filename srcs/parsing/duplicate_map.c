/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:03:57 by abchaban          #+#    #+#             */
/*   Updated: 2023/04/01 18:47:44 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	find_biggest_x_and_y(int *x, int *y, t_game *data)
{
	int	i;
	int	j;
	int	biggest_x;

	biggest_x = 0;
	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			j++;
			if (j > biggest_x)
				biggest_x = j;
		}
		j = 0;
		i++;
	}
	*x = biggest_x;
	*y = i;
}

void	fill_line_with_zero(char *map, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		map[i] = '0';
		i++;
	}
	map[i] = 0;
}

int	create_line_of_map(char **map, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < y)
	{
		map[i] = malloc(sizeof(char) * (x + 1));
		if (map[i] == NULL)
			return (0);
		fill_line_with_zero(map[i], x);
		i++;
	}
	map[i] = NULL;
	return (1);
}

void	fill_map(char **map, t_game *data)
{
	int	i;
	int	j;
	int	i_b;
	int	j_b;

	i = 1;
	j = 1;
	i_b = 0;
	j_b = 0;
	while (data->map[i_b])
	{
		while (map[i][j])
		{
			if (data->map[i_b][j_b] != 0)
			{
				map[i][j] = data->map[i_b][j_b];
				j_b++;
			}
			j++;
		}
		j_b = 0;
		j = 1;
		i_b++;
		i++;
	}
}

char	**create_map_cpy(int x, int y, t_game *data)
{
	char	**map;

	map = malloc(sizeof(char *) * (y + 1));
	if (map == NULL)
		return (NULL);
	if (create_line_of_map(map, x, y) == 0)
		return (0);
	fill_map(map, data);
	return (map);
}
