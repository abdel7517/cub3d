/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:52:40 by abchaban          #+#    #+#             */
/*   Updated: 2023/03/27 16:25:53 by abchaban         ###   ########.fr       */
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
		return (0);
	}
	return (1);
}

int check_id2(char *word)
{
	int static NO_S;
	int static SO_S;

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
	return (0);
}

int	check_id(char *word)
{
	int static WE_S;
	int static EA_S;

	if (check_id2(word))
		return(1);
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
	return (0);
}

int	is_id(char *word)
{
	int static F_S;

	if (word == NULL)
		return (0);
	if (check_id(word) == 1)
		return (1);
	if (ft_strcmp("F", word) == 0 && F_S == 0)
	{
		F_S = 1;
		return (1);
	}
	return (0);
}