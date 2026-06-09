#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	if (c == '\0' && s[i] == '\0')
	{
		return ((char *)&s[i]);
	}
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}
