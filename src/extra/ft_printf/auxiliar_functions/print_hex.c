/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-v <csilva-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 09:22:36 by csilva-v          #+#    #+#             */
/*   Updated: 2026/06/15 10:15:33 by csilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hex(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n > 15)
	{
		count += print_hex(n / 16, base);
	}
	ft_putchar_fd(base[n % 16], 1);
	count++;
	return (count);
}
