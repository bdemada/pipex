/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:41:29 by bde-mada          #+#    #+#             */
/*   Updated: 2023/04/25 18:54:05 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	ft_pow(double base, int exp)
{
	double	nb;

	if (exp == 0)
		return (1);
	nb = base;
	if (exp < 0)
	{
		exp *= -1;
		while (--exp)
			nb *= base;
		return (1 / nb);
	}
	return (nb);
}

/* int	main(void)
{
	printf("atof %lf\n", ft_atof("-10001.10000001e4"));
} */
