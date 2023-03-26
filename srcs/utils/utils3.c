/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:53:01 by abchaban          #+#    #+#             */
/*   Updated: 2023/03/26 16:53:18 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void free_file_in_game(t_game *data)
{
    int i;

    i = 0;
    if (data->file == NULL)
        return ;
    while (data->file[i])
    {
        free(data->file[i]);
        i++;
    }
    free(data->file);
    data->file = NULL;
}