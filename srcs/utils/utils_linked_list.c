/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:24:02 by abchaban          #+#    #+#             */
/*   Updated: 2023/05/16 09:59:27 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// void    add_last(t_line **lst, t_line *new)
// {
//     t_line  *current;

//     if (*lst == NULL)
//     {
//         *lst = new;
//         return ;
//     }
//     current = *lst;
//     while (current->next)
//         current = current->next;
//     current->next = new;
// }

// t_line  *create_node(int line, char *value)
// {
//     t_line *new;

//     new = malloc(sizeof(t_line));
//     new->line = line + 1;
//     new->next = NULL;
//     new->value = value;
//     return (new);
// }
