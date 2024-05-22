#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;
	for (i = 0; s[i]; i++);
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}

char	*ft_strdup(const char *str)
{
	char *dup = malloc(ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	ft_strcpy(dup, str);
	return (dup);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	if (!s1 || !s2)
		return (NULL);
	char *str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcpy((str + ft_strlen(s1)), s2);
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
	char		*line;
	char		*newline;
	int			bytes;
	int			cpy;

	line = ft_strdup(stash);
	while (!(newline = ft_strchr(line, '\n')) && (bytes = read(fd, stash, BUFFER_SIZE)))
	{
		stash[bytes] = '\0';
		line = ft_strjoin(line, stash);
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	if (newline != NULL)
	{
		cpy = newline - line + 1;
		ft_strcpy(stash, newline + 1);
	}
	else
	{
		cpy = ft_strlen(line);
		stash[0] = '\0';
	}
	line[cpy] = '\0';
	return (line);
}
