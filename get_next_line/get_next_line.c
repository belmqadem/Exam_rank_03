#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;
	for (i = 0; s[i]; i++);
	return (i);
}

char	*ft_strdup(const char *str)
{
	char *dup = malloc(ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	while (*str)
		*dup++ = *str++;
	*dup = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return (s);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char stash[BUFFER_SIZE + 1];
	char		*line = NULL;
	char		*newline = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;
	size_t		i, j;

	line = ft_strdup(stash);
	while (!(newline = ft_strchr(line, '\n')) && (bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	if (newline != NULL)
	{
		for (i = 0; line[i] && line[i] != '\n'; i++);
		if (line[i] == '\n')
			i++;
		for (j = 0; line[i] != '\0'; i++, j++)
			stash[j] = line[i];
		stash[j] = '\0';
		line[i - j] = '\0';
	}
	else
		stash[0] = '\0';
	return (line);
}
