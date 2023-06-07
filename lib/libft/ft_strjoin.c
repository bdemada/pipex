/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:41:45 by bde-mada          #+#    #+#             */
/*   Updated: 2023/05/03 14:27:13 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*sjoin;

	i = -1;
	j = -1;
	len = 0;
	if (s1)
		len += ft_strlen((char *)s1);
	if (s2)
		len += ft_strlen((char *)s2);
	sjoin = (char *)malloc((len + 1) * sizeof(char));
	if (!sjoin)
		return (NULL);
	while (s1 && s1[++i])
		sjoin[i] = s1[i];
	if (!s1)
		++i;
	while (s2 && s2[++j])
		sjoin[i + j] = s2[j];
	sjoin[i + j] = '\0';
	return (sjoin);
}
