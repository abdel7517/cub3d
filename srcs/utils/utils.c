/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:30:26 by abchaban          #+#    #+#             */
/*   Updated: 2023/04/01 18:56:46 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	size = ft_strlen(s1);
	str = (char *) malloc(sizeof(char) * (size + 1));
	while (*s1)
	{
		*str = *s1;
		s1++;
		str++;
	}
	*str = 0;
	return (str - size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *) s1);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (*dst && *src && i < len)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	if (i > 0)
		*dst = 0;
	return (dst - i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL || s == NULL)
		return (NULL);
	while (i < len)
	{
		if (s[start] != 3)
		{
			str[i] = s[start];
			i++;
		}
		start++;
	}
	str[i] = 0;
	return (str);
}
