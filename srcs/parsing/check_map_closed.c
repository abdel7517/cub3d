/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:07:43 by abchaban          #+#    #+#             */
/*   Updated: 2023/05/18 14:11:03 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	flood_fill(t_data *data, int x, int y, char value)
{
	if (data->map_cpy[x][y + 1] && data->map_cpy[x][y] != '1'
		&& data->map_cpy[x][y] != value)
	{
		data->map_cpy[x][y] = value;
		flood_fill(data, x, y + 1, value);
	}
	if (data->map_cpy[x + 1] && data->map_cpy[x][y] != '1'
		&& data->map_cpy[x + 1][y] != value)
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

int	check_if_map_is_closed(t_data *data)
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
	return (printf("Error\nThe map is not closed"), 0);
}

int	find_element_on_map(t_data *data)
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

int	find_starting_position(t_data *data, int *position)
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

int	find_bad_element_on_map(t_data *data)
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
				return (printf("Error\nBad char %c on map",
						data->map_cpy[i][j]), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
