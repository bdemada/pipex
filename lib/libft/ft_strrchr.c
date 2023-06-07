/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:11:28 by bde-mada          #+#    #+#             */
/*   Updated: 2022/12/06 17:54:57 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	chr;

	i = ft_strlen((char *)s);
	chr = (char) c;
	while (i >= 0)
	{
		if (s[i] == chr)
			return ((char *)s + i);
		i--;
	}
	if (chr == '\0')
		return ((char *)s + i);
	return (NULL);
}
