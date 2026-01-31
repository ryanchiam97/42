#include "tsp.h"

float	tsp_dist(t_city city1, t_city city2)
{
	float	x;
	float	y;
	float	dist;
	
	x = fabsf(city1.x - city2.x);
	y = fabsf(city1.y - city2.y);
	dist = sqrtf((x * x) + (y * y));
	
	return (dist);
}

float	tsp_path_dist(t_city *city, int *seq, int ncity)
{
	int	idx;
	float	dist;
	
	// return path
	dist = tsp_dist(city[seq[0] - 1], city[seq[ncity - 1] - 1]);
	
	// first city to the next till last city
	idx = -1;
	while (++idx < ncity - 1)
		dist += tsp_dist(city[seq[idx] - 1], city[seq[idx + 1] - 1]);
	return (dist);
}

void	tsp_show_city(t_city *city, int ncity)
{
	int	idx;
	
	fprintf(stdout, " Cities coordinate\n");
	idx = -1;
	while (++idx < ncity)
		fprintf(stdout," City[%d] : %6.2f %6.2f\n", idx + 1, city[idx].x, city[idx].y);
	fprintf(stdout, "\n");
}

void	tsp_show_path(t_city *city, int *seq, int ncity)
{
	int	idx;
	
	fprintf(stdout, " Path taken\n");
	idx = -1;
	while (++idx < ncity)
		fprintf(stdout," Node[%d] : City[%d] : %6.2f %6.2f\n", idx + 1, seq[idx], city[seq[idx] - 1].x, city[seq[idx] - 1].y);
	fprintf(stdout, "\n");
}

int	tsp_path(t_city *city, int *seq, int *best, int *use, int ncity, float *min, int s)
{
	int	idx;
	float	dist;
	
	// last stage
	if (s == ncity)
	{
		dist = tsp_path_dist(city, seq, ncity);
		if ((*min == -1) || (*min > dist))
		{
			*min = dist;
			memcpy(best, seq, sizeof(int) * ncity);
		}
		return (1);
	}
	
	// init
	idx = -1;
	
	// search
	while (1)
	{
		// next stage
		if (seq[s] != 0)
			tsp_path(city, seq, best, use, ncity, min, s + 1);
		
		// condition

		// deselect
		if (seq[s] != 0)
		{
			use[seq[s] - 1] = 0;
			seq[s] = 0;
		}
			
		// find next available route
		idx++;
		while ((idx < ncity) && (use[idx] != 0))
			idx++;
		if (idx == ncity)
			return (1);
		use[idx] = 1;
		seq[s] = idx + 1;
	}
	
	return (1);
}

int	main(void)
{
	t_city	*city;
	int	ncity;
	int	*seq;
	int	*use;
	int	*best;
	int	rd;
	float	dist;

	ncity = 0;
	city = 0;
		
	// get coordinates from stdin
	rd = 2;
	while ((rd == 2) || (rd != EOF))
	{
		city = (t_city *)realloc(city, sizeof(t_city) * (ncity + 1));
		if (city == 0)
			return (RTN_ERR);
		rd = fscanf(stdin, "%f, %f", &(city[ncity].x), &(city[ncity].y));
		if (rd == 2)
			ncity++;
	}
	if (rd != EOF)
	{
		free (city);
		return (RTN_ERR);
	}
	
	//tsp_show_city(city, ncity);
	
	// if ncity < 3, distance can be calculated directly
	if (ncity == 1)
		dist = 0;
	if (ncity == 2)
		dist = tsp_dist(city[0], city[1]) * 2;
	if (ncity == 3)
	{
		dist = tsp_dist(city[0], city[1]);
		dist += tsp_dist(city[1], city[2]);
		dist += tsp_dist(city[0], city[2]);
	}
	if (ncity <= 3)
	{
		fprintf(stdout, "%.2f", dist);
		return (RTN_OK);
	}
	
	// setup parameters
	seq = (int *)calloc(sizeof(int), ncity);
	if (seq == 0)
	{
		free (city);
		return (RTN_ERR);
	}
	use = (int *)calloc(sizeof(int), ncity);
	if (use == 0)
	{
		free (city);
		free (seq);
		return (RTN_ERR);
	}
	
	best = (int *)calloc(sizeof(int), ncity);
	if (best == 0)
	{
		free (city);
		free (seq);
		free (use);
		return (RTN_ERR);
	}
	
	dist = -1;
	tsp_path(city, seq, best, use, ncity, &dist, 0);
	fprintf(stdout, "%.2f\n", dist);
	
	//tsp_show_path(city, best, ncity);
	
	free (city);
	free (use);
	free (seq);
	free (best);
	
	return (RTN_OK);
}
