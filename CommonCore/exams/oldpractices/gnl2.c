/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:06:47 by rchiam            #+#    #+#             */
/*   Updated: 2026/01/28 13:41:36 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFERSIZE
# define BUFFERSIZE 100
#endif

char *ft_strchr(char *str, char c)// wrong... return long, not char. you want the index
// ft_str_chr_index or find char index...
{
	int i = 0;
// check string and if empty return -1
	while(str[i])// wrong. if str[i] !=0 AND str[i] != c, i++...
	{
		if (str[i] == c)// ++i only if not null or not == c
			return (&(str[i]));// stop there then return i if ==c
		i++;
	}
	return (0);// -1 not 0
}

// extend buffer function
// input: char *buffer
//vars: 

// char *rtn_str
// int len
// int i

// len = find_index(buffer, 0) + usual check if -1 return null

// rtn_str malloc and check. malloc size to len + BUFFERSIZE + 1

// i = 0 ... 
// while i < len... rtn_str[i] = buffer[i]
//rtn_str[i] = 0
// free buffer
// return rtn_str

char *return_nl_and_overwritebuf(char *str)// ok, but can call input buffer
{
	//vars used: (same as above)
	//    int len, 
	//    int i
	//    char * rtn_str
	
	char * n = ft_strchr(str, '\n');//wrong... use to get len. len=get_index + check if -1
	
	//rtn_str = malloc (len + 2) + check
//--------------------------------copy from buffer to rtn_str until \n
	// i = 0
	//while buffer[i] != \n
	//	rtnstr[i] = buffer[i]
	//	i++
//--------------settle the \n and \0
	//rtn_str[i] = buffer[i] - for the \n
	//i++
	// rtn_str[i] = \0 - null terminate
//-----------------overwrite buffer with remaining...
	//int rtn_str_len = i (note how much was )
	//while (buffer[i] != 0)
	//.. 	buffer[i - rtn_str_len] = buffer[i];
	//..	i++
	//buffer[i - rtn_str_len] = buffer[i]// ... handle the \0
	//return (rtn_Str)
}

char *get_next_line(int fd)
{
	//vars
	//	STATIC char *buffer
	// char			*rtn_Str
	// long			readlen;
	// long			bufferlen;

	// check fd... <0 or >1024, return 0

	// rtn_Str = return_nl_overwrite_buffer(buffer)
	// readlen = BUFFERSIZE
	
	//while (readlen == BUFFERSIZE && rtn_Str == 0)
		// buffer = extendbuffer(buffer)
		// buffer_len = ft_strchr_index(buffer, 0) + checks -1 & free-if-error
		// read_len = read(fd, &(buffer[buffer_len]), BUFFERSIZE) + checks -1 and freeiferror
		// buffer_len += readlen
		// buffer[bufferlen] = 0
		// rtnstr = return_nl_overwrite(buffer)
	
	//if rtnstr != 0 return rtn_Str (normal case)

	// if buffer[0] == 0
	// free buffer, set buffer to 0, rtn 0 (nothing read. EOF)

	// rtn_Str = buffer
	// buffer = 0
	// return rtn_Str (last case, no \n read... just return = buffer)

	}

int main(int argc, char** argv)
{
	// char *tmp
	//tmp = gnl()
	// while true
		// if tmp = 0, 
			// return error
		//if tmp[0]
			//print empty, exiting
		//printftmp
		//freetmp, return 0
}