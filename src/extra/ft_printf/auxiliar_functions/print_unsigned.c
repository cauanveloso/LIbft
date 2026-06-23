/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-v <csilva-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 09:23:12 by csilva-v          #+#    #+#             */
/*   Updated: 2026/06/16 15:43:43 by csilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_unsigned(unsigned	int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += print_unsigned(n / 10);
	}
	ft_putchar_fd(n % 10 + '0', 1);
	count++;
	return (count);
}
