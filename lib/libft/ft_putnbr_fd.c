/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:52:58 by bde-mada          #+#    #+#             */
/*   Updated: 2022/12/06 16:11:30 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	div;
	unsigned int	nb;

	div = 1;
	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -n;
	}
	while (nb / div >= 10)
		div *= 10;
	while (div > 1)
	{
		ft_putchar_fd((nb / div) + '0', fd);
		nb %= div;
		div /= 10;
	}
	ft_putchar_fd(nb + '0', fd);
}
