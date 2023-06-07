/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:43:31 by bde-mada          #+#    #+#             */
/*   Updated: 2022/12/19 16:19:59 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*substr;
	size_t	start;
	size_t	len;

	start = 0;
	substr = (char *)s1;
	if (!*s1)
		return (ft_strdup(""));
	if (!s1 || !set)
		return (ft_strdup(""));
	len = ft_strlen(substr);
	while (substr[start] && ft_strchr(set, substr[start]))
		start++;
	while (ft_strchr(set, substr[len - 1]) && len > start)
		len--;
	return (ft_substr((char *)s1, start, len - start));
}

/* int	main(void)
{
	char	*trim;

	char s1[] = "lorem ipsum dolor sit amet";
	trim = ft_strtrim("", "");
	return (0);
} */
