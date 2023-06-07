/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:42:23 by bde-mada          #+#    #+#             */
/*   Updated: 2022/12/03 12:15:37 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	mychar;
	char			*mystr;

	mychar = (unsigned char)c;
	mystr = (char *)b;
	while (len-- > 0)
		*mystr++ = mychar;
	return (b);
}
