/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-v <csilva-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 09:21:41 by csilva-v          #+#    #+#             */
/*   Updated: 2026/06/15 09:22:05 by csilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_format(char c, va_list args)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	else if (c == 's')
		return (print_str(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (print_int(va_arg(args, int)));
	else if (c == '%')
		return (print_char('%'));
	else if (c == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (print_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (print_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (print_pointer(va_arg(args, void *)));
	return (0);
}
