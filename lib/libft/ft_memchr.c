/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:07:31 by bde-mada          #+#    #+#             */
/*   Updated: 2022/12/02 16:11:15 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	mychar;
	size_t			i;
	char			*str;

	str = (char *)s;
	i = 0;
	mychar = (unsigned char)c;
	while (i < n)
	{
		if ((unsigned char)str[i] == mychar)
			return (str + i);
		i++;
	}
	return (NULL);
}
