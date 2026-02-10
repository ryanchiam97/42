#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void sort(char *str)
{
	int i = 0;
	if (!str)
		return;
	while (str[i])
	{
		int j = i + 1;
		while (str[j])
		{
			if (str[j] < str[i])
			{
				char tmp = str[j];
				str[j] = str[i];
				str[i] = tmp;
			}
			j++;
		}
		i++;
	}
}

void permute(char *str, int n, char *out, int *used, int pos)
{
	if (pos == n)
	{
		printf("%s\n",out);
		return;
	}
	int i = 0;
	while (i < n)
	{
		if (!used[i])
		{
			// if (i > 0 && str[i] == str[i - 1] && !used[i - 1])
			// {
			// 	i++;
			// 	continue;
			// }
			used[i] = 1;
			out[pos] = str[i];
			permute(str, n, out, used, pos + 1);
			used[i] = 0;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == 0)
		return (0);
	char *str = argv[1];
	sort(str);
	int n = strlen(str);
	int *used = calloc(sizeof(int), n);
	if (!used)
		return (1);
	char *out = malloc(n);
	if (!out)
		return (free(used), 1);
	permute(str, n, out, used, 0);
	free(used);
	free(out);
}