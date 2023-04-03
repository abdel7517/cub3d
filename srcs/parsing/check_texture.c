/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:52:40 by abchaban          #+#    #+#             */
/*   Updated: 2023/04/01 18:46:11 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	find_path(char *word)
{
	int	fd;

	fd = open(word, O_RDONLY);
	if (fd > 0)
	{
		close(fd);
		return (1);
	}
	return (0);
}

int	check_id2(char *word)
{
	int static	no_s;
	int static	so_s;

	if (ft_strcmp("NO", word) == 0 && no_s == 0)
	{
		no_s = 1;
		return (1);
	}
	if (ft_strcmp("SO", word) == 0 && so_s == 0)
	{
		so_s = 1;
		return (1);
	}
	return (0);
}

int	check_id(char *word)
{
	int static	we_s;
	int static	ea_s;

	if (check_id2(word))
		return (1);
	if (ft_strcmp("WE", word) == 0 && we_s == 0)
	{
		we_s = 1;
		return (1);
	}
	if (ft_strcmp("EA", word) == 0 && ea_s == 0)
	{
		ea_s = 1;
		return (1);
	}
	return (0);
}

int	is_id(char *word)
{
	int static	f_s;

	if (word == NULL)
		return (0);
	if (check_id(word) == 1)
		return (1);
	if (ft_strcmp("F", word) == 0 && f_s == 0)
	{
		f_s = 1;
		return (1);
	}
	return (0);
}
