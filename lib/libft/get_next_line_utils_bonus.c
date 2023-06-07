/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:09:11 by bde-mada          #+#    #+#             */
/*   Updated: 2023/04/17 15:44:16 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int		i;
	char	*str;
	char	chr;

	i = 0;
	str = (char *)s;
	chr = (char) c;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (str[i] == chr)
			return (str + i);
		i++;
	}
	if (chr == '\0')
		return (str + i);
	return (NULL);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize < 1)
		return (ft_strlen_gnl((char *)src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen_gnl((char *)src));
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*sjoin;

	i = 0;
	j = -1;
	len = ft_strlen_gnl((char *)s1) + ft_strlen_gnl((char *)s2);
	sjoin = (char *)malloc((len + 1) * sizeof(char));
	if (!sjoin)
	{
		free(s1);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		sjoin[i] = s1[i];
		i++;
	}
	while (s2 && s2[++j])
		sjoin[i + j] = s2[j];
	free(s1);
	sjoin[i + j] = '\0';
	return (sjoin);
}
