/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:30:33 by abchaban          #+#    #+#             */
/*   Updated: 2023/03/27 18:33:37 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"


int	check_format_of_color(char *word, int *digit_suit, int i)
{
	int	digit;
	int comma;

	comma = 0;
	digit = 0;

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
			*digit_suit = *digit_suit + 1;
		if (',' == word[i])
			comma++;
		else if (comma != 2)
			return (1);
		i++;
		digit = 0;
	}
	return (0);
}

int check_color(char *word)
{
	int	digit_suit;
	int i;

	i = 0;
	digit_suit = 0;
	if (word == NULL || (word[0] < '0' && word[0] > '9'))
		return (1);
	if (check_format_of_color(word, &digit_suit, i))
		return (1);
	if (digit_suit == 3)
		return (0);
	return (1);
}

int	loop_on_line_splited(char **line_splited, int *path_validated, int *color_validated, t_game *data)
{
	int	i;

	i = 0;
	while (line_splited[i])
	{
		if (is_id(line_splited[i]))
		{
			if (find_path(line_splited[i+1]) == 0)
			{
				*path_validated = 1;
				data->data = add_node(line_splited[i], line_splited[i + 1], data);
			}
			if (check_color(line_splited[i+1]) == 0)
			{
				data->data = add_node(line_splited[i], line_splited[i + 1], data);
				*color_validated = 1;
			}
			if (data->data == NULL)
					return (1);
		}
		i++;
	}
	return (0);
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
	if (loop_on_line_splited(line_splited, &path_validated, &color_validated, data))
		return (1);
	free_file(line_splited);
	if (path_validated || color_validated)
		*count_items = *count_items + 1;
	return (0);
}

int	check_element(t_game *data)
{
	int	count_items;
	int	i;

	i = 0;
	count_items = 0;
	while (data->file[i])
	{
		if (check_line(data->file[i], &count_items, data))
		{
			printf("ERROR\nIN LINE");
			return (1);
		}
		i++;
		if (count_items == 5)
			return (check_position_of_map_in_config_file(data, i));
	}
	printf("Error\nThere is a missing or an error in the config file (texture or color)");
	return (0);
}
