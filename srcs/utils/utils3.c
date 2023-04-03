/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:53:01 by abchaban          #+#    #+#             */
/*   Updated: 2023/04/01 19:02:10 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	free_file_in_game(t_game *data)
{
	int	i;

	i = 0;
	if (data->file == NULL)
		return ;
	while (data->file[i])
	{
		free(data->file[i]);
		i++;
	}
	free(data->file);
	data->file = NULL;
}

void	free_data_in_game(t_game *data)
{
	int	i;

	i = 0;
	if (data->data == NULL)
		return ;
	while (data->data[i])
	{
		free(data->data[i]);
		i++;
	}
	free(data->data);
	data->data = NULL;
}

char	**add_line_of_map(char *line, t_game *data)
{
	int		i;
	int		j;
	char	**new_file;

	i = 0;
	j = 0;
	if (data->map)
	{
		while (data->map[i])
		i++;
	}
	new_file = malloc(sizeof(char *) * (i + 2));
	if (new_file == NULL)
		return (NULL);
	while (j < i)
	{
		new_file[j] = ft_strdup(data->map[j]);
		j++;
	}
	new_file[j] = ft_strdup(line);
	if (new_file[j] == NULL)
		return (NULL);
	new_file[++j] = 0;
	free_file(data->map);
	return (new_file);
}

char	**cpy_old_file_and_add_new_line(char **file, char *line)
{
	int		i;
	int		j;
	char	**new_file;

	i = 0;
	j = 0;
	while (file[i])
		i++;
	new_file = malloc(sizeof(char *) * (i + 2));
	if (new_file == NULL)
		return (NULL);
	while (j < i)
	{
		new_file[j] = ft_strdup(file[j]);
		j++;
	}
	new_file[j] = ft_strdup(line);
	if (new_file[j] == NULL)
		return (NULL);
	new_file[++j] = 0;
	free_file(file);
	return (new_file);
}

int	check_path(t_game *data, char **line_splited, int *path_validated, int i)
{
	if (find_path(line_splited[i + 1]) == 0)
		return (0);
	*path_validated = 1;
	data->data = add_node(line_splited[i], line_splited[i + 1], data);
	return (1);
}
