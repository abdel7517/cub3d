/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:24:02 by abchaban          #+#    #+#             */
/*   Updated: 2023/03/26 01:19:30 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
