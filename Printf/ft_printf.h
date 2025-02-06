/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:03:22 by atran             #+#    #+#             */
/*   Updated: 2024/11/13 22:03:58 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_unsigned_nbr(unsigned int n);
int	ft_unsigned_hex(uint64_t n, char c);
int	ft_putnbr(int64_t n);
int	ft_putchar(char c);
int	ft_putstr(char *s);

#endif
