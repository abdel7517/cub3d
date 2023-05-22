/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:10:00 by obouhlel          #+#    #+#             */
/*   Updated: 2023/05/22 15:34:33 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
}

void	destroy_data(t_data *data)
{
	free_file(data->map);
	free_file(data->file);
	free_file(data->data);
	free_file(data->map_cpy);
}
