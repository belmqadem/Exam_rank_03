#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 13
#endif

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char    *ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
char    *ft_strchr(char *s, int c);
char	*get_next_line(int fd);

#endif
