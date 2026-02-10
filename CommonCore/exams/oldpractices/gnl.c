#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int has_nl(char *str)
{
    int i = 0;
    while (str && str[i])
    {
        if (str[i] == '\n')
            return 1;
        i++;
    }
    return 0;
}

int ft_strlen(char *str)
{
    int i = 0;
    if (!str) return 0;
    while (str[i])
        i++;
    return i;
}

char *ft_strjoin(char *s1, char *s2)
{
    int i = 0, j = 0;
    char *new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!new)
    {
        free(s1);
        return 0;
    }
    while (s1 && s1[i])
        new[j++] = s1[i++];
    i = 0;
    while (s2 && s2[i])
        new[j++] = s2[i++];
    new[j] = 0;
    free(s1);
    return (new);
}

char *extractline(char *s)
{
    char *line;
    int i = 0;

    while (s[i] && s[i]!='\n')
        i++;
    line = malloc(i + (s[i]=='\n') + 1);
    if (!line)
        return 0;
    i = 0;
    while (s[i] && s[i]!='\n')
    {
        line[i] = s[i];
        i++;
    }
    if (s[i]=='\n')
    {
        line[i] = '\n';
        i++;
    }
    line[i] = 0;
    return line;
}

char *trimstash(char *s)
{
    int i = 0;
    int j = 0;
    char *new;
    while (s[i] && s[i]!='\n')
        i++;
    if (!s[i])
    {
        free(s);
        return NULL;
    }
    i++;
    new = malloc(ft_strlen(s) - i + 1);
    if (!new)
        return NULL;
    while (s[i])
        new[j++] = s[i++];
    new[j] = 0;
    free(s);
    return (new);
}

char *get_next_line(int fd)
{
    static char *stash;
    char buffer[BUFFER_SIZE + 1];
    int r;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    while(!has_nl(stash) && (r = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[r] = 0;
        stash = ft_strjoin(stash, buffer);
    }
    if (!stash)
        return NULL;
    line = extractline(stash);
    stash = trimstash(stash);
    return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main (int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("error arg");
        return 1;
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return(perror("open"), 1);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
