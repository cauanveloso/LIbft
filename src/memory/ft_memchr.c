#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst;

	i = 0;
	dst = (unsigned char *)s;
	while (i < n)
	{
		if (dst[i] == (unsigned char)c)
		{
			return ((void *)&dst[i]);
		}
		i++;
	}
	return (NULL);
}
