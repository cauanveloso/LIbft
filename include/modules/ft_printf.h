/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-v <csilva-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:02:19 by csilva-v          #+#    #+#             */
/*   Updated: 2026/06/15 09:21:28 by csilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	handle_format(char c, va_list args);
int	print_char(char c);
int	print_str(char *s);
int	print_int(int n);
int	print_hex(unsigned long n, char *base);
int	print_unsigned(unsigned int n);
int	print_pointer(void *ptr);

#endif