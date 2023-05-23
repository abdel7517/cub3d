/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:48:57 by obouhlel          #+#    #+#             */
/*   Updated: 2023/05/23 09:18:10 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (nmemb && size)
		if (nmemb * size / size != nmemb)
			return (NULL);
	s = (void *)malloc(nmemb * size);
	if (!s)
		return (NULL);
	ft_bzero(s, (nmemb * size));
	return (s);
}

void	ft_close(int *fd)
{
	if (*fd < 0)
		return ;
	close(*fd);
}

void	ft_free(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	ft_print_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		printf("%s\n", strs[i++]);
}
