#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void getmin(char *str, int *remR, int *remL)
{
	int i = 0;
	int strbal = 0;
	*remL = 0;
	*remR = 0;
	while (str[i])
	{
		if (str[i] == '(')
			strbal++;
		else
		{
			if (strbal == 0)
				(*remR)++;
			else
				strbal--;
		}
		i++;
	}
	*remL = strbal;
}

void dfs(int idx, char *str, int n, int rmL, int rmR, int outbal, char *out)
{
	if (rmL + rmR > n - idx)
		return ;
	if (n == idx)
	{
		out[n] = 0;
		if (rmL == 0 && rmR == 0 && outbal == 0)
			puts(out);
		return ;
	}
	if (str[idx] == '(')
	{
		if (rmL > 0)
		{
			out[idx]=' ';
			dfs(idx + 1, str, n, rmL- 1, rmR, outbal, out);
		}
		out[idx] = '(';
		dfs(idx + 1, str, n, rmL, rmR, outbal + 1, out);
	}
	else
	{
		if (rmR > 0)
		{
			out[idx]=' ';
			dfs(idx + 1, str, n, rmL, rmR - 1, outbal, out);
		}
		if (outbal > 0)
		{
			out[idx] = ')';
			dfs(idx + 1, str, n, rmL, rmR, outbal - 1, out);
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	char *str = argv[1];
	int len = (int)strlen(str);
	int remR = 0;
	int remL = 0;
	getmin(str, &remR, &remL);
	//char *out = malloc(len + 1);
	//if (!out)
	//	return (1);
	//out[len] = 0;
	char out[len + 1];
	out[len] = 0;
	dfs(0, str, len, remL, remR, 0, out);
}