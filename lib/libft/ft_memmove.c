/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:19:35 by bde-mada          #+#    #+#             */
/*   Updated: 2022/12/06 18:00:00 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*csrc;
	char	*cdest;
	size_t	i;

	csrc = (char *)src;
	cdest = (char *)dest;
	if (!csrc && !cdest)
		return (0);
	i = 0;
	if (src < dest)
	{
		i = len;
		while (i--)
			cdest[i] = csrc[i];
	}
	else
	{
		while (len--)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (dest);
}
/*
int main(void)
{
   char dest[] = "oldstring";
   const char src[]  = "newstring";

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   ft_memmove(dest, src, 9);
   printf("After memmove dest = %s, src = %s\n", dest, src);

   return(0);
}
*/
