/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:24:12 by obouhlel          #+#    #+#             */
/*   Updated: 2023/05/16 10:30:43 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	close_window(t_game *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	exit(EXIT_SUCCESS);
}

static int	keyboard(int keycode, t_game *data)
{
	if (keycode == ESCAPE)
		close_window(data);
	return (EXIT_SUCCESS);
}

int	window_init(t_game *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (EXIT_FAILURE);
	data->win = mlx_new_window(data->mlx, WIN_X, WIN_Y, "cub3D");
	if (!data->win)
		return (EXIT_FAILURE);
	mlx_key_hook(data->win, &keyboard, data);
	mlx_hook(data->win, ON_KEYDOWN, KEYPRESSMASK, &keyboard, data);
	mlx_hook(data->win, ON_DESTROY, NOEVENTMASK, &close_window, data);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
