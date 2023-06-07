/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:52:01 by bde-mada          #+#    #+#             */
/*   Updated: 2023/05/25 13:59:32 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_formatter(char formatter, va_list args)
{
	if (formatter == 'c')
		return (ft_putchar_printf(va_arg(args, unsigned int)));
	if (formatter == 's')
		return (ft_putstr_printf(va_arg(args, char *)));
	if (formatter == 'p')
		return (ft_address_printf(va_arg(args, unsigned long long)));
	if (formatter == 'd' || formatter == 'i')
		return (ft_putnbr_printf(va_arg(args, int)));
	if (formatter == 'u')
		return (ft_putnbr_unsig_printf(va_arg(args, unsigned int)));
	if (formatter == 'x' || formatter == 'X')
		return (ft_puthex_printf(va_arg(args, unsigned int), formatter));
	if (formatter == '%')
		return (ft_putchar_printf('%'));
	return (-1);
}

//i[0] str index
//i[1] printed count
//i[2] printed insde a formatter
int	ft_printf(const char *str, ...)
{
	int		i[3];
	va_list	args;

	i[0] = -1;
	i[1] = 0;
	va_start(args, str);
	while (str[++i[0]])
	{
		if (str[i[0]] != '%')
		{
			if (ft_putchar_printf(str[i[0]]) == -1)
				return (-1);
			else
				i[1]++;
		}
		else
		{
			i[2] = check_formatter(str[++i[0]], args);
			if (i[2] == -1)
				return (-1);
			i[1] += i[2];
		}
	}
	va_end(args);
	return (i[1]);
}

/* int	main(void)
{
	int		i;
	int		j;
	char	str[] = "perro";

//	i = ft_printf("asbd, %s %d %p \n", str, 123, str);
//	j = printf("asbd, %s %d %p \n", str, 123, str);
	i = ft_printf("%ss%ss%ss", "And ", "some other", "joined");
	ft_printf("\n");
	j = printf("%ss%ss%ss", "And ", "some other", "joined");
	printf("\n");
	printf("Printed 1: %d\n", i);
	printf("Printed 2: %d\n", j);
//	i = ft_printf("%cc%cc%c", 'a', '\t', 'b');
//	printf("\nPrinted: %d\n", i);
//	printf("asbd, %s %d %p \n", str, 123, str);
//	i = ft_printf("asbd, %0s %d %p \n", str, 123, str);
//	printf("asbd, %s %d %p \n", str, 123, str);
	return (0);
} */
