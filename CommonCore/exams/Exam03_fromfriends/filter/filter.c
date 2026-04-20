#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// stdin buffer read size
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

// Return code
#define RTN_ERR	1
#define RTN_OK	0

int	main(int argc, char **argv)
{
	char	*rd_str;
	char	*tmp_str;
	long	buffer_len;
	long	rd_len;

	// check arguments
	if ((argc != 2) || (argv[1][0] == 0))
		return (RTN_ERR);
	
	// setup parameters
	rd_str = (char *)calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (rd_str == 0)
	{
		perror("Error");
		return (RTN_ERR);
	}
	buffer_len = 0;
	rd_len = BUFFER_SIZE;
	
	// get next line
	while (rd_len == BUFFER_SIZE)
	{
		rd_len = read(0, &(rd_str[buffer_len]), BUFFER_SIZE);
		if (rd_len == -1)
		{
			free (rd_str);
			perror("Error");
			return (RTN_ERR);
		}
		buffer_len += rd_len;
		if (rd_len == BUFFER_SIZE)
		{
			rd_str = realloc(rd_str, BUFFER_SIZE + buffer_len + 1);
			if (rd_str == 0)
			{
				perror("Error");
				return (RTN_ERR);
			}
		}
	}
	rd_str[buffer_len + 1] = 0;
	
	// filter the input string
	tmp_str = rd_str;
	rd_len = strlen(argv[1]);
	while (tmp_str != 0)
	{
		tmp_str = (char *)memmem(tmp_str, strlen(tmp_str), argv[1], rd_len);
		buffer_len =-1;
		while ((tmp_str != 0) && (++buffer_len < rd_len))
			tmp_str[buffer_len] = '*';
	}
	
	// print result
	printf ("%s\n", rd_str);
	
	// end program
	free (rd_str);
	return (RTN_OK);
}
