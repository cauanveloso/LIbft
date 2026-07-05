#include"libft.h"

static char *extract_line(char *storage)
{
	size_t i;
	size_t len;
	char *ptr;
	char *dst;

	if (!storage || storage[0] == '\0')
		return (NULL);
	ptr = ft_strchr(storage, DELIMITER);
	if (ptr != NULL)
		len = (ptr - storage + 1);
	else
		len = ft_strlen(storage);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = storage[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char *clean_storage(char *storage)
{
	char *dst;
	char *ptr;

	if (!storage)
		return (NULL);
	ptr = ft_strchr(storage, DELIMITER);
	if (!ptr)
	{
		free(storage);
		return (NULL);
	}
	ptr = ptr + 1;
	if (*ptr == '\0')
	{
		free(storage);
		return (NULL);
	}
	dst = ft_strdup(ptr);
	if (!dst)
	{
		free(storage);
		return (NULL);
	}
	free(storage);
	return (dst);
}

static int append_buffer(char **storage, char *buffer, int bytes)
{
	char *tmp;
	buffer[bytes] = '\0';
	tmp = ft_strjoin(*storage, buffer);
	free(*storage);
	if (!tmp)
	{
		storage = NULL;
		return (0);
	}
	*storage = tmp;
	return (1);
}

static char *read_file(int fd, char *storage)
{
	int byte_read;
	char *buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte_read = 0;
	while (!ft_strchr(storage, DELIMITER))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read <= 0)
			break;
		if (!append_buffer(&storage, buffer, byte_read))
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	if (byte_read < 0)
	{
		free(storage);
		return (NULL);
	}
	return (storage);
}

char *get_next_line(int fd)
{
	static char *storage[MAX_FD];
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	if (!storage[fd])
	{
		storage[fd] = ft_strdup("");
		if (!storage[fd])
			return (NULL);
	}
	storage[fd] = read_file(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = extract_line(storage[fd]);
	if (!line)
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	storage[fd] = clean_storage(storage[fd]);
	return (line);
}