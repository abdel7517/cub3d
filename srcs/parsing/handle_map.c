/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:03:48 by abchaban          #+#    #+#             */
/*   Updated: 2023/04/01 16:44:38 by abchaban         ###   ########.fr       */
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

void	flood_fill(t_game *data, int x, int y, char value)
{
	if (data->map_cpy[x][y + 1] && data->map_cpy[x][y] != '1' && data->map_cpy[x][y] != value) 
	{
		data->map_cpy[x][y] = value;
		flood_fill(data, x, y + 1, value);
	}
	if (data->map_cpy[x + 1] && data->map_cpy[x][y] != '1' && data->map_cpy[x + 1][y] != value)
	{
		data->map_cpy[x][y] = value;
		flood_fill(data, x + 1, y, value);
	}
	if (x > 0 && data->map_cpy[x][y] != '1' && data->map_cpy[x - 1][y] != value)
	{
		data->map_cpy[x][y] = value;
		flood_fill(data, x - 1, y, value);
	}
	if (y > 0 && data->map_cpy[x][y] != '1' && data->map_cpy[x][y - 1] != value)
	{
		data->map_cpy[x][y] = value;
		flood_fill(data, x, y - 1, value);
	}
}

int find_starting_position(t_game *data, int *position)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map_cpy[i])
	{
		j = 0;
		while (data->map_cpy[i][j])
		{
			if (data->map_cpy[i][j] == 'N' || data->map_cpy[i][j] == 'S' 
				|| data->map_cpy[i][j] == 'E' || data->map_cpy[i][j] == 'W')
			{
				if (*position == 0)
					*position = 1;
				else
					return (printf("Error\nMultiple starting position"), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	find_bad_element_on_map(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map_cpy[i])
	{
		j = 0;
		while (data->map_cpy[i][j])
		{
			if (data->map_cpy[i][j] != 'N' && data->map_cpy[i][j] != 'S' 
				&& data->map_cpy[i][j] != 'E' && data->map_cpy[i][j] != 'W'
				&& data->map_cpy[i][j] != '0' && data->map_cpy[i][j] != '1'
				&& data->map_cpy[i][j] != ' ' && data->map_cpy[i][j] != '	'
				&& data->map_cpy[i][j] != -1)
			{
					return (printf("Error\nBad char %c on map", data->map_cpy[i][j]), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int check_if_map_is_closed(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map_cpy[i])
	{
		j = 0;
		while (data->map_cpy[i][j])
		{
			if (data->map_cpy[i][j] != '1' && data->map_cpy[i][j] != -1)
					return (1);
			j++;
		}
		i++;
	}
	return (printf("Error\nThe map is not closed"),0);
}

int	find_element_on_map(t_game *data)
{
	int		position;

	position = 0;
	if (check_if_map_is_closed(data) == 0)
		return (0);
	if (find_starting_position(data, &position) == 0)
		return (0);
	if (position == 0)
		return (printf("Error\nStarting position not found"), 0);
	if (find_bad_element_on_map(data) == 0)
		return (0);	
	return (1);
}

int	check_map(t_game *data)
{
	int		x;
	int		y;
	char	**map_cpy;

	x = 0;
	y = 0;
	find_biggest_x_and_y(&x, &y, data);
	map_cpy = create_map_cpy(x + 2, y + 2, data);
	if (map_cpy == NULL)
		return (0);
	data->map_cpy = map_cpy;
	flood_fill(data, 0, 0, -1);
	if (find_element_on_map(data) == 0)
		return (0);
	return (1);
}
