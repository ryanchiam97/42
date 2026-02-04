/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalfilter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:43:53 by user42            #+#    #+#             */
/*   Updated: 2026/02/04 23:47:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#ifndef BUFFERSIZE
# define BUFFERSIZE 10
#endif

int main(int argc, char **argv)
{
    char tmp[BUFFERSIZE];
    int totallen = 0;
    int readlen = 0;
    char* rtn_line = NULL;
    
    if (argc != 2 || argv[1][0] == 0)
        return (1);

    while ((readlen = (int)read(0, tmp, BUFFERSIZE)) > 0)
    {
        char *t = realloc(rtn_line, totallen + readlen + 1);
        if (!t)
            return (free(rtn_line), perror("Error: "), 1);
        rtn_line = t;
        memcpy(rtn_line + totallen, tmp, readlen);
        totallen += readlen;
    }
    if (readlen < 0)
        return (free(rtn_line), perror("Error: "), 1);
    if (!rtn_line)
        return (0);
    rtn_line[totallen] = 0;
    
    int i = 0;
    char *filter = argv[1];
    int filterlen = (int)strlen(filter);
    while (i + filterlen <= totallen)
    {
        int j = 0;
        while (rtn_line[i + j] && filter[j] && rtn_line[i+j] == filter[j] && j < filterlen)
            j++;
        if (j == filterlen)
        {
            int k = i + j;
            while (i < k)
            {
                rtn_line[i] = '*';
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    printf("%s\n", rtn_line);
//    write(1, rtn_line, totallen);
    free(rtn_line);
    return (0);
}
*/
/*
=======================================================================================================================
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef BUFFERSIZE
# define BUFFERSIZE 10
#endif

int main(int argc, char **argv)
{
    char    tmp[BUFFERSIZE];
    char    *buf = NULL;
    size_t  len = 0;
    ssize_t r = 0;                 // IMPORTANT: initialized
    size_t  patlen;
    size_t  i;

    if (argc != 2 || argv[1][0] == '\0')
        return 1;

    patlen = strlen(argv[1]);

    while ((r = read(0, tmp, BUFFERSIZE)) > 0)
    {
        char *t = realloc(buf, len + (size_t)r + 1);
        if (!t)
            return (free(buf), perror("Error"), 1);
        buf = t;

        memcpy(buf + len, tmp, (size_t)r);
        len += (size_t)r;
    }
    if (r < 0)
        return (free(buf), perror("Error"), 1);

    if (!buf)          // empty stdin -> output nothing, success
        return 0;

    buf[len] = '\0';

    i = 0;
    while (i + patlen <= len)
    {
        size_t j = 0;
        while (j < patlen && buf[i + j] == argv[1][j])
            j++;

        if (j == patlen)
        {
            j = 0;
            while (j < patlen)
                buf[i + j++] = '*';
            i += patlen;          // sed-style (non-overlapping)
        }
        else
            i++;
    }

    write(1, buf, len);
    free(buf);
    return 0;
}

*/

/*
================================================================================================================
 #include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char *ft_strncpy(char *dest, char *src, size_t n)
{
    size_t i;

    for (i = 0; i < n; i++)
        dest[i] = src[i];
    for (; i < n ; i++)
        dest[i] = '\0';
    return (dest);
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

void search_and_replace(char *original, char *replace)
{
    size_t i = 0;
    size_t j;
    size_t len  = strlen(replace);

    while (original[i])
    {
        if (ft_strncmp(original + i, replace, len) == 0)
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
            write(1, original + i, 1);
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
        perror("Error: ");\
        return (1);
    }
    while ((read_bytes = read(0, buffer, BUFFER_SIZE)) > 0)
    {
        ft_strncpy(line + total_bytes, buffer, read_bytes);
        total_bytes = total_bytes + read_bytes;
    }
    if (read_bytes < 0)
    {
        perror("Error: ");
        free(line);
        return (1);
    }
    line[total_bytes] = 0;
    search_and_replace(line, av[1]);
    free(line);
    return(0);
}
    */