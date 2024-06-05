#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

static char *ft_strchr(const char *s, int c)
{
    if (!s)
        return NULL;

    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }

    return NULL;
}

static char *extract_line(char **store)
{
    char *newline_pos = ft_strchr(*store, '\n');
    char *line;
    char *temp;

    if (newline_pos)
    {
        size_t len = newline_pos - *store + 1;
        line = ft_substr(*store, 0, len);
        temp = ft_strdup(*store + len);
        free(*store);
        *store = temp;
        if (**store == '\0')
        {
            free(*store);
            *store = NULL;
        }
    }
    else
    {
        line = ft_strdup(*store);
        free(*store);
        *store = NULL;
    }
    return line;
}

static char *ft_strjoin_free(char *s1, char const *s2)
{
    char *joined_str = ft_strjoin(s1, s2);
    free(s1);
    return joined_str;
}

char *get_next_line(int fd)
{
    static char *store;
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    while (!ft_strchr(store, '\n') && (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        store = ft_strjoin_free(store, buffer);
        if (!store)
            return NULL;
    }
    if (bytes_read < 0)
    {
        if (store)
            free(store);
        return NULL;
    }
    if (store && *store)
        return extract_line(&store);
    return NULL;
}




