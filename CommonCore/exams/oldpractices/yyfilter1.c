#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2
#endif

char *ft_strncpy(char *dest, const char *src, size_t n)
{
   size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++)
       dest[i] = src[i];
    for ( ; i < n; i++)
        dest[i] = '\0';
    return dest;
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i = 0;

    while (i < n && s1[i] && s2[i] && (s1[i] == s2[i]))
        i++;
    if (i == n)
        return (0);
    return (s1[i] - s2[i]);
}

void search_and_replace(char *orignal, char *replace)
{
    size_t i = 0;
    size_t j;
    size_t len = strlen(replace);

    while (orignal[i])
    {
        if (ft_strncmp(orignal + i, replace, len)  == 0)
        {
            j = 0;
            while (j < len)
            {
                write(1, "*", 1);
                i++;
                j++;
            }
        }
        else
        {
            write(1, orignal + i , 1);
            i++;
        }
    }
}

int main (int ac, char **av)
{
    ssize_t read_bytes;
    ssize_t total_bytes = 0;
    char buffer[BUFFER_SIZE + 1];
    char *line;

    if (ac != 2)
        return (1);
    line = malloc(100000);
    if (!line)
    {
        perror ("malloc");
        return (1);
    }
    while ((read_bytes = read(0, buffer, BUFFER_SIZE)) > 0)
    {
        ft_strncpy(line + total_bytes, buffer, read_bytes);
        total_bytes = total_bytes +read_bytes;
    }
    if (read_bytes < 0)
    {
        perror("read");
        return (free(line), 1);
    }
    line[total_bytes] = '\0';
    search_and_replace(line, av[1]);
    free(line);
    return (0);
}
