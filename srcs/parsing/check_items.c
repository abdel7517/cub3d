/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:30:33 by abchaban          #+#    #+#             */
/*   Updated: 2023/03/26 16:47:35 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_id(char *word)
{
	int static NO_S;
	int static SO_S;
	int static WE_S;
	int static EA_S;
	int static F_S;

	if (word == NULL)
		return (0);
	if (ft_strcmp("NO", word) == 0 && NO_S == 0)
	{
		NO_S = 1;
		return (1);
	}
	if (ft_strcmp("SO", word) == 0 && SO_S == 0)
	{
		SO_S = 1;
		return (1);
	}
	if (ft_strcmp("WE", word) == 0 && WE_S == 0)
	{
		WE_S = 1;
		return (1);
	}
	if (ft_strcmp("EA", word) == 0 && EA_S == 0)
	{
		EA_S = 1;
		return (1);
	}
	if (ft_strcmp("F", word) == 0 && F_S == 0)
	{
		F_S = 1;
		return (1);
	}
	return (0);
}
int	find_path(char *word)
{
	int	fd;

	fd = open(word, O_RDONLY);
	if (fd > 0)
	{
		close(fd);	
		return (0);
	}
	return (1);
}


int check_color(char *word)
{
	int i;
	int	comma;
	int	digit;
	int	digit_suit;

	digit_suit = 0;
	digit = 0;
	comma = 0;
	i = 0;
	if (word == NULL || (word[i] < '0' && word[i] > '9'))
		return (1);
	while(word[i])
	{
		while (word[i] >= '0' && word[i] <= '9')
		{
			i++;
			digit++;
		}
		if (digit == 0 || digit > 3)
			return (1);
		else
			digit_suit++;
		if (',' == word[i])
			comma++;
		else if (comma != 2)
			return (1);
		i++;
		digit = 0;
	}
	if (digit_suit == 3)
		return (0);
	return (1);
}

int check_line(char *line, int *count_items, t_game *data)
{
	int		i;
	char	**line_splited;
	int		path_validated;
	int		color_validated;

	color_validated = 0;
	path_validated = 0;
	i = 0;
	line_splited = ft_split(line, ' ');
	while (line_splited[i])
	{
		if (is_id(line_splited[i]))
		{
			if (find_path(line_splited[i+1]) == 0)
			{
				path_validated = 1;
				data->data = add_node(line_splited[i], line_splited[i + 1], data);
			}
			if (check_color(line_splited[i+1]) == 0)
			{
				data->data = add_node(line_splited[i], line_splited[i + 1], data);
				color_validated = 1;
			}
		}
		i++;
	}
	free_file(line_splited);
	if (path_validated || color_validated)
		*count_items = *count_items + 1;
	return (0);
}

int	check_element(char **file, t_game *data)
{
	int	count_items;
	int	i;

	i = 0;
	count_items = 0;
	(void)file;
	while (data->file[i])
	{
		printf("line %d->%s and count = %d\n", i, data->file[i], count_items);
		if (check_line(data->file[i], &count_items, data))
			return (1);
		i++;
	}
	free_file_in_game(data);
	i = 0;
	printf("--------%s---------\n", get_element("F", data));
	while (data->data[i])
		printf("%s\n", data->data[i++]);
	free_file_in_game(data);
	if (count_items == 5)
		return (0);
	return (1);
}