/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:18:40 by abchaban          #+#    #+#             */
/*   Updated: 2023/04/03 15:05:46 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (s1[i] == 0 && s2[i] != 0)
		return (-1);
	if (s2[i] == 0 && s1[i] != 0)
		return (1);
	return (0);
}

char	*create_new_key_value(char *key, char *value)
{
	char	*key_value;
	char	*tmp;

	tmp = ft_strjoin(key, ":");
	if (tmp == NULL)
		return (NULL);
	key_value = ft_strjoin(tmp, value);
	free(tmp);
	if (key_value == NULL)
		return (NULL);
	return (key_value);
}

char	**add_node(char *key, char *value, t_game *data)
{
	int		i;
	int		j;
	char	**new_file;

	i = 0;
	j = 0;
	if (data->data)
	{
		while (data->data[i])
		i++;
	}
	new_file = malloc(sizeof(char *) * (i + 2));
	if (new_file == NULL)
		return (NULL);
	while (j < i)
	{
		new_file[j] = ft_strdup(data->data[j]);
		j++;
	}
	new_file[j] = create_new_key_value(key, value);
	if (new_file[j] == NULL)
		return (NULL);
	new_file[++j] = 0;
	free_file(data->data);
	return (new_file);
}

char	*get_element(char *key, t_game *data)
{
	int		i;
	char	**value;

	value = NULL;
	i = 0;
	while (data->data[i])
	{
		value = ft_split(data->data[i], ':');
		if (value == NULL)
			return (NULL);
		if (ft_strcmp(key, value[0]) == 0)
			return (value[1]);
		i++;
	}
	return (NULL);
}

void	free_file(char **file)
{
	int	i;

	i = 0;
	if (file == NULL)
		return ;
	while (file[i])
	{
		free(file[i]);
		i++;
	}
	free(file);
}
