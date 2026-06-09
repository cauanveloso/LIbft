#include "libft.h"

size_t	ft_numlen(long n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*dst;
	size_t	size;
	size_t	neg;

	nb = n;
	size = ft_numlen(nb);
	dst = malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	dst[size] = '\0';
	neg = (nb < 0);
	if (neg)
	{
		nb *= -1;
		dst[0] = '-';
	}
	while (size > neg)
	{
		size--;
		dst[size] = nb % 10 + '0';
		nb /= 10;
	}
	return (dst);
}
