/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:03:48 by abchaban          #+#    #+#             */
/*   Updated: 2023/03/27 15:45:08 by abchaban         ###   ########.fr       */
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
			return (1);
		i++;
	}
	return (0);
}

int	check_map(t_game *data, int i)
{
	int	end;

	end = 1;
	printf("%d\n", i);

	while (data->file[i])
	{
		if (map_start(data->file[i]))
		{
			while (data->file[i])
			{
				if (!map_start(data->file[i]))
					return (check_element_after_map(data, i));
				// printf("%s\n", data->file[i]);
				data->map = add_line_of_map(data->file[i], data);
				i++;
			}
			break ;
		}
		i++;
	}
	return (0);
}