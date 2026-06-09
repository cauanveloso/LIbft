#include "libft.h"

static size_t ft_count(char const *str, char c)
{
	size_t i;
	size_t count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if ((i == 0 && str[i] != c) || (i > 0 && str[i - 1] == c && str[i] != c))
		{
			count++;
		}
		i++;
	}
	return (count);
}

static size_t ft_size(char const *str, char c)
{
	size_t len;

	len = 0;
	while (str[len] && str[len] != c)
	{
		len++;
	}
	return (len);
}

static char *ft_copy(char const *str, char c)
{
	size_t i;
	char *dst;

	i = 0;
	dst = malloc(sizeof(char) * (ft_size(str, c) + 1));
	if (!(dst))
	{
		return (NULL);
	}
	while (str[i] && str[i] != c)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void *ft_free_all(char **cats, size_t i)
{
	while (i > 0)
	{
		i--;
		free(cats[i]);
	}
	free(cats);
	return (NULL);
}

char **ft_split(char const *s, char c)
{
	size_t i;
	size_t j;
	char **dst;

	if (!s)
		return (NULL);
	dst = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break;
		dst[j] = ft_copy(&s[i], c);
		if (!dst[j])
			return (ft_free_all(dst, j));
		i += ft_size(&s[i], c);
		j++;
	}
	dst[j] = NULL;
	return (dst);
}
