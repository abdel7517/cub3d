/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:10:00 by obouhlel          #+#    #+#             */
/*   Updated: 2023/05/18 14:14:03 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	init_data(t_data *data)
{
	data->data = NULL;
	data->file = NULL;
	data->map = NULL;
	data->path = NULL;
	data->map_cpy = NULL;
	data->mlx = NULL;
	data->win = NULL;
}

void	destroy_data(t_data *data)
{
	free_file(data->map);
	free_file(data->file);
	free_file(data->data);
	free_file(data->map_cpy);
}
