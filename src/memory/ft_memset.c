#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	unsigned char	*dst;

	i = 0;
	dst = (unsigned char *)s;
	while (i < n)
	{
		dst[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
