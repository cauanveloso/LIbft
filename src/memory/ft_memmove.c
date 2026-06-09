#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;
	unsigned char *d;
	const unsigned char *s;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s && d < s + n)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
