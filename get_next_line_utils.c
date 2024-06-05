#include "get_next_line.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t len1 = 0, len2 = 0;
    while (s1 && s1[len1])
        len1++;
    while (s2 && s2[len2])
        len2++;
    char *result = malloc(len1 + len2 + 1);
    if (!result)
        return NULL;
    size_t i = 0;
    for (i = 0; i < len1; i++)
        result[i] = s1[i];
    for (i = 0; i < len2; i++)
        result[len1 + i] = s2[i];
    result[len1 + len2] = '\0';
    return result;
}

char *ft_strdup(const char *s1)
{
    size_t len = 0;
    while (s1 && s1[len])
        len++;
    char *dup = malloc(len + 1);
    if (!dup)
        return NULL;
    for (size_t i = 0; i < len; i++)
        dup[i] = s1[i];
    dup[len] = '\0';
    return dup;
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i = 0;
    if (!s)
        return NULL;
    while (s[start + i] && i < len)
        i++;
    char *sub = malloc(i + 1);
    if (!sub)
        return NULL;
    for (size_t j = 0; j < i; j++)
        sub[j] = s[start + j];
    sub[i] = '\0';
    return sub;
}
