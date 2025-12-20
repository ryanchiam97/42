#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef
# define BUFFER_SIZE 5
#endif

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        perror("Error: should have only 1 argument");
    }
    else
    {
        char* filter = argv[1];
        int filterlen = strlen(filter);
        char *window = malloc(filterlen);
        if (!window)
            return (perror("Error: malloc error"), 1);
        int windowlen = 0;
        char buffer[BUFFER_SIZE];
        while (true)
        {
            bytesread = read(0, buffer, BUFFER_SIZE);
            if (bytesread < 0)
            {
                perror("Error: read error");
                free(window);
                return(1)
            }
            else if (bytesread == 0)
                break;//EOF
            else
            {
                for (int i = 0; i < bytesread; i++)
                {
                    window[windowlen] = bytesread[i];
                    windowlen++;
                    if (windowlen < filterlen)
                        continue;
                    int match = 1;
                    for (int j = 0; j < filterlen; j++)
                    {
                        if (window[j] != filter[j])
                        {
                            match = 0;
                            break;
                        }
                    }
                    if (match)
                    {
                        while (filterlen--)
                            printf("*");
                        windowlen = 0;
                    }
                    else
                    {
                        printf(window[0]);
                        int k = 0;
                        while(window[k + 1])
                        {
                            window[k] = window[k+1];
                            k++;
                        }
                        windowlen = filterlen - 1;
                    }
                }
            }
        }
        int i = 0;
        while (window[i])
        {
            printf(window[i]);
            i++;
        }
    }
}