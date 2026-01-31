/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ryangnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:25:13 by rchiam            #+#    #+#             */
/*   Updated: 2026/01/31 16:02:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef BUFFERSIZE
# define BUFFERSIZE 10
#endif

int get_char_index(char *str, char c)
{
    int i = 0;

    if (!str)
        return (-1);
    while (str[i] && str[i] != c)
        i++;
    if (str[i] == c)
        return (i);
    return (-1);
}

char *extend_buffer(char *buffer)
{
    int len = get_char_index(buffer, 0);
    if (len == -1)
        return (0);
    char *new_buffer = malloc(len + BUFFERSIZE + 1);
    if (!new_buffer)
        return (0);
    int i = 0;
    while (i < len)
    {
        new_buffer[i] = buffer[i];
        i++;
    }
    new_buffer[i] == '\0';
    free(buffer);
    return(new_buffer);
}

char *return_nl_overwrite(char *buffer)
{
    if (!buffer)
        return (-1);
    int len = get_char_index(buffer, '\n');
    if (len == -1)
        return (free(buffer), 0);
    char *rtn_str = malloc(len + 2);
    if (!rtn_str)
        return (free(buffer), -1);
    int i = 0;
    while (i < len)
    {
        rtn_str[i] = buffer[i];
        i++;
    }
    rtn_str[i] = '\n';
    i++;
    rtn_str[i] = '\0';
    int j = 0;
    while (buffer[i])
    {
        buffer[j] = buffer[i];
        i++;
        j++;
    }
    buffer[j] = '\0';
    return (rtn_str);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *rtn_str;
    int readlen;
    int totallen;

    if (fd < 0 || fd > 1024)
        return (0);

    readlen = BUFFERSIZE;
    rtn_str = return_nl_overwrite(buffer);
    while (readlen == BUFFERSIZE && rtn_str == 0)
    {
        buffer = extend_buffer(buffer);
        totallen = get_char_index(buffer, 0);
        if (totallen == -1)
        {
            if (buffer != 0)
                free(buffer);
            buffer = 0;
        }
        readlen = read(fd, &(buffer[totallen]), BUFFERSIZE);
        if (read == -1)
        {
            free(buffer);
            buffer = 0;
            return (0);
        }
        totallen += readlen;
        buffer[totallen] = '\0';
        rtn_str = return_nl_overwrite(buffer);
    }
    if (rtn_str != 0)
        return (rtn_str);
    if (buffer[0] == 0)
    {
        free(buffer);
        buffer = 0;
        return (0);
    }
    rtn_str = buffer;
    buffer = 0;
    return (rtn_str);
}

int main(int argc, char **argv)
{
    //
}