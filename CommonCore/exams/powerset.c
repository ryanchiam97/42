#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print_subset(int *subset, int subsetlen)
{
	if (!subset || !subset[0])
		return ;
	printf("%i", subset[0]);
	int i = 1;
	while ( i < subsetlen)
	{
		printf(" %i", subset[i]);
		i++;
	}
	printf("\n");
}

void dfs(int *values, int max, int *subset, int subsetlen, int idx, int target, int sum)
{
	if (idx == max)
	{
		if (target == sum)
			print_subset(subset, subsetlen);
		return ;
	}
	subset[subsetlen] = values[idx];
	dfs(values, max, subset, subsetlen + 1, idx + 1, target, sum + subset[subsetlen]);
	dfs(values, max, subset, subsetlen, idx + 1, target, sum);
}

int main(int argc, char **argv)
{
	if (argc <= 2 || argv[1][0] == 0)
		return (1);
	int target = atoi(argv[1]);
	int max = argc - 2;
	int *values = malloc(sizeof(int) * max);
	if (!values)
		return (1);
	int i = 0;
	while (i + 2 < argc)
	{
		values[i] = atoi(argv[i + 2]);
		i++;
	}
	int *subset = malloc(sizeof(int) * max);
	dfs(values, max, subset, 0, 0, target, 0);
	free(values);
	free(subset);
}