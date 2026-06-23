/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-v <csilva-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 09:22:47 by csilva-v          #+#    #+#             */
/*   Updated: 2026/06/15 09:22:52 by csilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_int(int n)
{
	int		count;
	long	nb;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count++;
		ft_putchar_fd('-', 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		count += print_int((int)(nb / 10));
	}
	ft_putchar_fd(nb % 10 + '0', 1);
	count++;
	return (count);
}
