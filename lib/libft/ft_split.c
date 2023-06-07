/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:44:32 by bde-mada          #+#    #+#             */
/*   Updated: 2022/12/07 13:29:59 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	list_size(char const *s1, char c)
{
	int	count;
	int	check;

	count = 0;
	check = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1)
	{
		if (*s1 == c)
			check = 0;
		else if (check == 0)
		{
			check = 1;
			count++;
		}
		s1++;
	}
	return (count);
}

static int	word_size(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i])
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char	**err_free(char const **list, int i)
{
	while (i > 0)
	{
		i--;
		free((void *)list[i]);
	}
	free(list);
	return (NULL);
}

static char	**fill_list(char const *s, char **list, char c, int len)
{
	int	i;
	int	word;
	int	pos;

	i = 0;
	word = 0;
	while (s[i] && word < len)
	{
		pos = 0;
		while (s[i] == c)
			i++;
		list[word] = (char *)malloc(sizeof(char) * word_size(s, c, i) + 1);
		if (list[word] == NULL)
			return (err_free((char const **)list, word));
		while (s[i] != '\0' && s[i] != c)
			list[word][pos++] = s[i++];
		list[word][pos] = '\0';
		word++;
	}
	list[word] = 0;
	return (list);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	int		len;

	if (s == NULL)
		return (NULL);
	len = list_size(s, c);
	list = (char **)malloc(sizeof(char *) * (len + 1));
	if (list == NULL)
		return (NULL);
	return (fill_list(s, list, c, len));
}
