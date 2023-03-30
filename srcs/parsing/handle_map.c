/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:03:48 by abchaban          #+#    #+#             */
/*   Updated: 2023/03/30 16:30:43 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int map_start(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '\n' && line[i] != ' ' && line[i] != 0 && line[i] != 9)
			return (1);
		i++;
	}
	return (0);
}

int check_element_after_map(t_game *data, int i)
{
	while (data->file[i])
	{
		if (map_start(data->file[i]))
		{
			printf("ERROR\nThe map is not the last element of file");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_position_of_map_in_config_file(t_game *data, int i)
{
	int	end;

	end = 1;
	while (data->file[i])
	{
		if (map_start(data->file[i]))
		{
			while (data->file[i])
			{
				if (!map_start(data->file[i]))
					return (check_element_after_map(data, i));
				data->map = add_line_of_map(data->file[i], data);
				i++;
			}
			return (check_element_after_map(data, i));
		}
		i++;
	}
	return (0);
}

void	find_biggest_x_and_y(int *x, int *y, t_game *data)
{
	int	i;
	int	j;
	int biggest_x;

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

void	fill_line_with_space(char **map, int i, int j)
{
	printf("i = %d et j = %d\n", i , j);

	while (map[i][j])
	{
	printf("in\n");
		map[i][j] = '0';
		j++;
	}
}

void	fill_line_with_zero(char *map, int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		map[i] = '0';
		i++;			
	}
	map[i] = 0;
}

void	create_line_of_map(char **map, int x, int y)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < y)
	{
		map[i] = malloc(sizeof(char) * (x + 1));
		fill_line_with_zero(map[i], x);
		i++;
	}
	map[i] = NULL;
}

char **create_map_cpy(int x, int y, t_game *data)
{
	int	i;
	int	j;
	int	i_b;
	int	j_b;
	char	**map;

	i = 1;
	j = 1;
	i_b = 0;
	j_b = 0;
	map = malloc(sizeof(char *) * (y + 1));
	if (map == NULL)
		return (NULL);
	create_line_of_map(map, x, y);
	(void)data;
	while (data->map[i_b])
	{
		while (map[i][j])
		{
			if (data->map[i_b][j_b] != 0)
				map[i][j] = data->map[i_b][j_b];
			j++;
			j_b++;
		}
		j_b = 0;
		j = 1;
		i_b++;
		i++;
	}
	return (map);
}

int	check_map(t_game *data)
{
	int		x;
	int		y;
	char	**map_cpy;

	x = 0;
	y = 0;
	find_biggest_x_and_y(&x, &y, data);
	printf("x = %d, y = %d\n", x, y);
	map_cpy = create_map_cpy(x + 2, y + 2, data);
	int i = 0;
	int j = 0;

	/*----- REPLACE ALL ELEMENT  */
	while (map_cpy[i])
	{
		while (map_cpy[i][j])
		{
			if (map_cpy[i][j] == ' ' && map_cpy[i][j] != '	')
				map_cpy[i][j] = '0';
			j++;
		}
		j = 0;
		i++;
	}


	i = 0;
	while (map_cpy[i])
	{
		printf("%s\n", map_cpy[i]);
		i++;
	}
	free_file(map_cpy);
	return (1);
}