/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:07:36 by abchaban          #+#    #+#             */
/*   Updated: 2023/05/22 15:33:58 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data);
	if (ac != 2)
		return (printf(ERROR_ARG), EXIT_FAILURE);
	if (launch(av[1], &data) == EXIT_FAILURE)
		return (destroy_data(&data), EXIT_FAILURE);
	if (window_init(&data) == EXIT_FAILURE)
		return (destroy_data(&data), EXIT_FAILURE);
	return (destroy_data(&data), EXIT_SUCCESS);
}
