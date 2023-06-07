/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:38:15 by bde-mada          #+#    #+#             */
/*   Updated: 2022/12/07 12:13:22 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dest;

	len = ft_strlen((char *)s1);
	dest = (char *)ft_calloc(len + 1, sizeof(char));
	if (!dest)
	{
		return (NULL);
		errno = 12;
	}
	dest[len] = '\0';
	len--;
	while (len >= 0)
	{
		dest[len] = s1[len];
		len--;
	}
	return (dest);
}
