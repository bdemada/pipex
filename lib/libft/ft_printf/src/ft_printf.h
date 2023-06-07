/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:31:04 by bde-mada          #+#    #+#             */
/*   Updated: 2023/05/25 14:17:49 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <sys/types.h>

int		ft_printf(char const *str, ...);
int		check_formatter(char formatter, va_list args);
int		ft_putstr_printf(char *s);
int		ft_puthex_printf(unsigned int nb, char formatter);
int		ft_address_printf(unsigned long long nb);
int		ft_putnbr_printf(int value);
int		ft_putnbr_unsig_printf(unsigned int value);

ssize_t	ft_putchar_printf(int c);

#endif
