/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:41:29 by bde-mada          #+#    #+#             */
/*   Updated: 2023/04/25 18:56:14 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_num(char *s, double *init)
{
	int	len;

	len = 0;
	while (ft_isdigit(*s))
	{
		*init = (*init * 10.0) + (*s - '0');
		s++;
		len++;
	}
	return (len);
}

static double	exp_calc(char *s, int exp, double nb)
{
	int	sign;
	int	e;

	sign = 1;
	e = 0;
	if (*s == 'e' || *s == 'E')
	{
		s++;
		if (*s == '-')
			sign *= -1;
		if (*s == '-' || *s == '+')
			s++;
	}
	while (ft_isdigit(*s))
	{
		e = (e * 10) + (*s - '0');
		s++;
	}
	exp += (sign * e);
	nb = nb * ft_pow(10, exp);
	return (nb);
}

double	ft_atof(const char *s)
{
	double	nb;
	int		sign;
	int		exp;

	nb = 0;
	sign = 1;
	exp = 0;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	s += calc_num((char *)s, &nb);
	if (*s == '.')
	{
		s++;
		exp -= calc_num((char *)s, &nb);
	}
	while (ft_isdigit(*s))
		s++;
	nb = exp_calc((char *)s, exp, nb);
	return (nb * (double)sign);
}

/* int	main(void)
{
	printf("atof %lf\n", ft_atof("-10001.10000001e4"));
} */
