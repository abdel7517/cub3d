/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:30:33 by abchaban          #+#    #+#             */
/*   Updated: 2023/03/25 15:36:30 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_id(char *word)
{
	int static NO;
	int static SO;
	int static WE;
	int static EA;
	int static F;

	if (word == NULL)
		return (0);
	if (ft_strcmp("NO", word) == 0 && NO == 0)
	{
		NO = 1;
		return (1);
	}
	if (ft_strcmp("SO", word) == 0 && SO == 0)
	{
		SO = 1;
		return (1);
	}
	if (ft_strcmp("WE", word) == 0 && WE == 0)
	{
		WE = 1;
		return (1);
	}
	if (ft_strcmp("EA", word) == 0 && EA == 0)
	{
		EA = 1;
		return (1);
	}
	if (ft_strcmp("F", word) == 0 && F == 0)
	{
		F = 1;
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

int check_line(char *line, int *count_items)
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
				path_validated = 1;
			if (check_color(line_splited[i+1]) == 0)
				color_validated = 1;
		}
		i++;
	}
	if (path_validated || color_validated)
		*count_items = *count_items + 1;
	return (0);
}

int	check_element(char **file)
{
	int	count_items;
	int	i;

	i = 0;
	count_items = 0;
	while (file[i])
	{
		if (check_line(file[i], &count_items))
			return (1);
		printf("line %d->%s and count = %d\n", i, file[i], count_items);
		i++;
	}
	if (count_items == 5)
		return (0);
	return (1);
}