/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-v <csilva-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 09:22:55 by csilva-v          #+#    #+#             */
/*   Updated: 2026/06/16 15:43:49 by csilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_pointer(void *ptr)
{
	int				count;
	unsigned long	nb;

	nb = (unsigned long)ptr;
	count = 2;
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		count += print_hex(nb, "0123456789abcdef");
	}
	return (count);
}
