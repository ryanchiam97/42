/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloh <hloh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:15:13 by hloh              #+#    #+#             */
/*   Updated: 2026/01/20 15:52:44 by hloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define READ_SIZE 4096

int main (int ac, char **av)
{
    if (ac != 2 || !av[1][0])
        return (1);

    char *needle = av[1]; //what we are searching for 
    int   n_len = strlen(needle);
    
    char *buf = malloc(READ_SIZE + n_len + 1);
    if (!buf) return (1);

    int len = 0;
    int bytes_read;

    while ((bytes_read = read(0, buf + len, READ_SIZE)) > 0)
    {
        len += bytes_read;
        buf[len] = '\0'; //To cap it off , safety null-terminator

        char *cursor = buf;
        char *match;
        while ((match = memmem(cursor, len - (cursor - buf),  needle , n_len)))
        {
            write (1, cursor, match - cursor);
            for(int i = 0; i< n_len;i++) write(1, "*", 1);
            cursor = match + n_len;
        }
        //cursor is now at the start of unprinted data.

        //edge case of where abc which is needle might be 'a''bc' , 
        //cut up improperly by the read and buffer by accident so need to manage
        //So now we need to cut and manage the remaining buffer properly for the next loop...
        int remaining = len - (cursor - buf);
        int keep = n_len - 1;
        if (remaining > keep)
        {
            write (1, cursor, remaining - keep);
            cursor += (remaining - keep);
            remaining = keep;
        }
        if (remaining > 0)
            memmove(buf, cursor, remaining);
        
        len = remaining;
    }
    // 2. THE CLEANUP (After the loop finishes reading EVERYTHING)
    // If the file ended and we still have "a" in the buffer, it wasn't part of "abc".
    // So we print it now.
        if (len > 0) write (1, buf, len);
        
        free(buf);
        return (0);
}
