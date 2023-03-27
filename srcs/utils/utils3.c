/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:53:01 by abchaban          #+#    #+#             */
/*   Updated: 2023/03/27 15:48:40 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void free_file_in_game(t_game *data)
{
    int i;

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

void free_data_in_game(t_game *data)
{
    int i;

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

char    **add_line_of_map(char *line, t_game *data)
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
