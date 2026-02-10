#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int findnl(char *str)
{
	int i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
int ft_strlen(char *s)
{
	int i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char *freejoin(char *stash, int stashlen, char *buffer, int bufferlen)
{
	if (!stash)
	{
		char* new = malloc(bufferlen + 1);
		if (!new) return 0;
		int i = 0;
		while (i < bufferlen)
		{
			new[i] = buffer[i];
			i++;
		}
		new[i] = 0;
		return (new);
	}
	char *newstash = malloc(stashlen + bufferlen + 1);
	if (!newstash)
		return (0);
	int i = 0;
	int j = 0;
	while (i < stashlen)
	{
		newstash[i] = stash[i];
		i++;
	}
	while (j < bufferlen)
	{
		newstash[i + j] = buffer[j];
		j++;
	}
	newstash[i + j] = '\0';
	free(stash);
	return (newstash);
}

char *substrdupe(char *stash, int start, int len)
{
	if (!stash)
		return (0);
	char *rtn_str = malloc(len + 1);
	if (!rtn_str)
		return (0);
	int i = 0;
	while (stash[start + i] && i < len)
	{
		rtn_str[i] = stash[start + i];
		i++;
	}
	rtn_str[i] = 0;
	return (rtn_str);
}

char *get_next_line(int fd)
{
	static char *stash[1024];
	char buf[BUFFER_SIZE + 1];
	int nl;
	int rd;

	if (fd < 0 || fd >= 1024)
		return (0);
	rd = 1;
	while ((nl = findnl(stash[fd])) == -1 && rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
			return (free(stash[fd]), stash[fd] = 0, NULL);
		if (rd == 0)
			break ;
		buf[rd] = 0;
		stash[fd] = freejoin(stash[fd], ft_strlen(stash[fd]), buf, rd);
		if (!(stash[fd]))
			return (free(stash[fd]), stash[fd] = 0, NULL);
	}
	if (nl != -1)
	{
		char *line = substrdupe(stash[fd], 0, nl + 1);
		char *remaining = substrdupe(stash[fd], nl + 1, ft_strlen(stash[fd]) - (nl + 1));
		free(stash[fd]);
		stash[fd] = remaining;
		if (!line || !(stash[fd]))
			return (free(stash[fd]), free(line), stash[fd] = 0, NULL);
		return (line);
	}
	if (!stash[fd] || stash[fd][0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = 0;
		return (0);
	}
	{
		char *line = stash[fd];
		stash[fd] = 0;
		return (line);
	}
}
#include <stdio.h>
int main(void)
{
	char *tmp;
	while ((tmp = get_next_line(0)))
	{
		printf("%s",tmp);
		free(tmp);
	}
	return (0);
}