/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:03:48 by abchaban          #+#    #+#             */
/*   Updated: 2023/05/16 09:10:14 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	map_start(char *line)
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

int	check_element_after_map(t_game *data, int i)
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
