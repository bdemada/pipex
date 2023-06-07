/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:46:26 by bde-mada          #+#    #+#             */
/*   Updated: 2022/12/12 12:38:46 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*write_function(unsigned int nb, int n, int div, char *s)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		s[0] = '-';
		i++;
	}
	while (div > 1)
	{
		s[i] = (nb / div) + '0';
		nb %= div;
		div /= 10;
		i++;
	}
	s[i] = (nb + '0');
	s[i + 1] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	unsigned int	div;
	int				i;
	unsigned int	nb;
	char			*s;

	i = 0;
	div = 1;
	nb = n;
	if (n < 0)
	{
		nb = -n;
		i++;
	}
	while (nb / div >= 10)
	{
		div *= 10;
		i++;
	}
	s = (char *)ft_calloc(i + 2, sizeof(char));
	if (!s)
		return (NULL);
	write_function(nb, n, div, s);
	return (s);
}

/* int	main(void)
{
	int		nb;
	char	*s;

	nb = -1567456;
	printf("numint: %d\n", nb);
	s = ft_itoa(nb);
	printf("numchar: %s", s);
	return (0);
} */
