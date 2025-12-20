#include <unistd.h>
#include <stdlib.h>


int has_nl(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return 0;
}

int ft_strlen(char * str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

char *ft_strjoin(char *s1, char *s2)
{
    if (!s2)
        return (s1);
    int l1 = ft_strlen(s1);
    int l2 = ft_strlen(s2);
    char *new = malloc(l1 + l2 + 1);
    if (!new)
        return (0);
    int i = 0;
    int j = 0;
    while (s1[i])
    {
        new[j] = s1[i];
        i++;
        j++;
    }
    i = 0;
    while (s2[i])
    {
        new[j] = s2[i];
        i++;
        j++;
    }
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
        line[i] == '\n';
        i++;
    }
    line[i] = 0;
    return line;
}
char *trimstash()