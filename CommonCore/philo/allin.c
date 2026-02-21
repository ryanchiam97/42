/*
MAKEFILE

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -Iincludes

SRC = src/main.c src/parse.c src/init.c src/routine.c src/time.c src/utils.c src/clean.c src/monitor.c src/routine_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -pthread -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

*/

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	t_data				*data;

	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;

	long				last_meal_ms;
	int					meals_eaten;
	pthread_mutex_t		meal_mtx;
}						t_philo;

typedef struct s_data
{
	int					n;
	long				t_die;
	long				t_eat;
	long				t_sleep;
	int					must_eat;

	long				start_ms;
	int					stop;
	int					seats;

	pthread_mutex_t		stop_mtx;
	pthread_mutex_t		print_mtx;
	pthread_mutex_t		*forks;
	pthread_mutex_t		seat_mtx;

	t_philo				*philos;
}						t_data;

int						parse_args(t_data *d, int ac, char **av);
int						init_all(t_data *d);

long					now_ms(void);
int						should_stop(t_data *d);
void					set_stop(t_data *d);

void					print_action(t_philo *p, const char *msg);
void					*philo_routine(void *arg);
void					clean_all(t_data *d);

void					die_and_stop(t_data *d, int id);
long					get_last_meal_ms(t_philo *p);
void					*monitor_routine(void *arg);

void					take_forks(t_philo *p);
void					*one_philo_case(t_philo *p);
void					eat(t_philo *p);
void					put_forks(t_philo *p);
void					sleep_and_think(t_philo *p);

void					smart_sleep(long ms, t_data *d);
void					wait_seat(t_data *d);
void					leave_seat(t_data *d);
#endif

void	clean_all(t_data *d)
{
	int	i;

	if (d->forks)
	{
		i = 0;
		while (i < d->n)
		{
			pthread_mutex_destroy(&d->forks[i]);
			pthread_mutex_destroy(&d->philos[i].meal_mtx);
			i++;
		}
		free(d->forks);
	}
	if (d->philos)
		free(d->philos);
	pthread_mutex_destroy(&d->stop_mtx);
	pthread_mutex_destroy(&d->print_mtx);
	pthread_mutex_destroy(&d->seat_mtx);
}

static int	init_mutexes(t_data *d)
{
	if (pthread_mutex_init(&d->stop_mtx, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&d->print_mtx, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&d->seat_mtx, NULL) != 0)
		return (1);
	return (0);
}

static void	init_philo(t_data *d, int i)
{
	pthread_mutex_init(&d->forks[i], NULL);
	pthread_mutex_init(&d->philos[i].meal_mtx, NULL);
	d->philos[i].last_meal_ms = d->start_ms;
	d->philos[i].meals_eaten = 0;
	d->philos[i].id = i + 1;
	d->philos[i].data = d;
	d->philos[i].left_fork = &d->forks[i];
	d->philos[i].right_fork = &d->forks[(i + 1) % d->n];
}

int	init_all(t_data *d)
{
	int	i;

	d->stop = 0;
	if (init_mutexes(d))
		return (1);
	d->seats = d->n - 1;
	d->forks = malloc(sizeof(pthread_mutex_t) * d->n);
	if (!d->forks)
		return (1);
	d->philos = (t_philo *)malloc(sizeof(t_philo) * d->n);
	if (!d->philos)
		return (1);
	i = 0;
	while (i < d->n)
		init_philo(d, i++);
	return (0);
}

static int	launch_philos(t_data *d, int *created)
{
	*created = 0;
	while (*created < d->n)
	{
		if (pthread_create(&d->philos[*created].thread, NULL, philo_routine,
				&d->philos[*created]) != 0)
		{
			set_stop(d);
			write(2, "Error: thread create\n", 21);
			return (1);
		}
		(*created)++;
	}
	return (0);
}

static int	launch_monitor(t_data *d, pthread_t *monitor)
{
	if (should_stop(d))
		return (0);
	if (pthread_create(monitor, NULL, monitor_routine, d) != 0)
	{
		set_stop(d);
		write(2, "Error: monitor create\n", 22);
		return (0);
	}
	return (1);
}

static void	join_philos(t_data *d, int created)
{
	int	i;

	i = 0;
	while (i < created)
	{
		pthread_join(d->philos[i].thread, NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data		d;
	int			created;
	int			monitor_created;
	pthread_t	monitor;

	if (parse_args(&d, ac, av))
		return (write(2, "Error: invalid args\n", 20), 1);
	d.start_ms = now_ms();
	if (init_all(&d))
		return (write(2, "Error: init failed\n", 19), 1);
	if (launch_philos(&d, &created))
		return (clean_all(&d), 1);
	monitor_created = launch_monitor(&d, &monitor);
	if (monitor_created)
		pthread_join(monitor, NULL);
	set_stop(&d);
	join_philos(&d, created);
	clean_all(&d);
	return (0);
}

/*
int	main(int ac, char **av)
{
	t_data		d;
	int			i;
	int			created;
	int			monitor_created;
	pthread_t	monitor;

	if (parse_args(&d, ac, av))
		return (write(2, "Error: invalid args\n", 20), 1);
	d.start_ms = now_ms();
	if (init_all(&d))
		return (write(2, "Error: init failed\n", 19), 1);
	created = 0;
	while (created < d.n)
	{
		if (pthread_create(&d.philos[created].thread, NULL, philo_routine,
				&d.philos[created]) != 0)
		{
			set_stop(&d);
			write(2, "Error: thread create\n", 21);
			break ;
		}
		created++;
	}
	monitor_created = 0;
	if (!should_stop(&d))
	{
		if (pthread_create(&monitor, NULL, monitor_routine, &d) == 0)
			monitor_created = 1;
		else
			set_stop(&d);
	}
	if (monitor_created)
		pthread_join(monitor, NULL);
	set_stop(&d);
	i = 0;
	while (i < created)
	{
		pthread_join(d.philos[i].thread, NULL);
		i++;
	}
	clean_all(&d);
	return (0);
}
*/
static int	get_meals(t_philo *p)
{
	int	v;

	pthread_mutex_lock(&p->meal_mtx);
	v = p->meals_eaten;
	pthread_mutex_unlock(&p->meal_mtx);
	return (v);
}

static int	everyone_ate_enough(t_data *d)
{
	int	i;

	if (d->must_eat <= 0)
		return (0);
	i = 0;
	while (i < d->n)
	{
		if (get_meals(&d->philos[i]) < d->must_eat)
			return (0);
		i++;
	}
	return (1);
}

long	get_last_meal_ms(t_philo *p)
{
	long	v;

	pthread_mutex_lock(&p->meal_mtx);
	v = p->last_meal_ms;
	pthread_mutex_unlock(&p->meal_mtx);
	return (v);
}

void	die_and_stop(t_data *d, int id)
{
	long	ts;

	pthread_mutex_lock(&d->stop_mtx);
	if (d->stop)
	{
		pthread_mutex_unlock(&d->stop_mtx);
		return ;
	}
	d->stop = 1;
	pthread_mutex_unlock(&d->stop_mtx);
	pthread_mutex_lock(&d->print_mtx);
	ts = now_ms() - d->start_ms;
	printf("%ld %d died\n", ts, id);
	pthread_mutex_unlock(&d->print_mtx);
}

void	*monitor_routine(void *arg)
{
	t_data	*d;
	int		i;
	long	last;
	long	now;

	d = (t_data *)arg;
	while (!should_stop(d))
	{
		i = 0;
		while (i < d->n && !should_stop(d))
		{
			last = get_last_meal_ms(&d->philos[i]);
			now = now_ms();
			if (now - last > d->t_die)
			{
				die_and_stop(d, d->philos[i].id);
				return (NULL);
			}
			i++;
		}
		if (everyone_ate_enough(d))
			return (set_stop(d), NULL);
		usleep(1000);
	}
	return (NULL);
}
static int	is_num(const char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static long	atolong(const char *s)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	while (s[i])
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (n);
}

int	parse_args(t_data *d, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	if ((!is_num(av[1]) || !is_num(av[2]) || !is_num(av[3]) || !is_num(av[4]))
		|| (ac == 6 && !is_num(av[5])))
		return (1);
	d->n = (int)atolong(av[1]);
	d->t_die = atolong(av[2]);
	d->t_eat = atolong(av[3]);
	d->t_sleep = atolong(av[4]);
	d->must_eat = -1;
	if (ac == 6)
		d->must_eat = (int)atolong(av[5]);
	if (d->n <= 0 || d->t_eat <= 0 || d->t_die <= 0 || d->t_sleep <= 0)
		return (1);
	return (0);
}
void	*one_philo_case(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	print_action(p, "has taken a fork");
	while (!should_stop(p->data))
		usleep(1000);
	pthread_mutex_unlock(p->left_fork);
	return (NULL);
}

void	take_forks(t_philo *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->right_fork);
		print_action(p, "has taken a fork");
		pthread_mutex_lock(p->left_fork);
		print_action(p, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(p->left_fork);
		print_action(p, "has taken a fork");
		pthread_mutex_lock(p->right_fork);
		print_action(p, "has taken a fork");
	}
}

void	eat(t_philo *p)
{
	print_action(p, "is eating");
	pthread_mutex_lock(&p->meal_mtx);
	p->last_meal_ms = now_ms();
	p->meals_eaten++;
	pthread_mutex_unlock(&p->meal_mtx);
	smart_sleep(p->data->t_eat, p->data);
}

void	put_forks(t_philo *p)
{
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}

void	sleep_and_think(t_philo *p)
{
	print_action(p, "is sleeping");
	smart_sleep(p->data->t_sleep, p->data);
	print_action(p, "is thinking");
}
void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->data->n == 1)
		return (one_philo_case(p));
	if (p->id % 2 == 0)
		usleep(1000);
	while (!should_stop(p->data))
	{
		wait_seat(p->data);
		take_forks(p);
		eat(p);
		put_forks(p);
		leave_seat(p->data);
		sleep_and_think(p);
	}
	return (NULL);
}
long	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

void	smart_sleep(long ms, t_data *d)
{
	long	end;

	end = now_ms() + ms;
	while (!should_stop(d) && now_ms() < end)
		usleep(200);
}
int	should_stop(t_data *d)
{
	int	v;

	pthread_mutex_lock(&d->stop_mtx);
	v = d->stop;
	pthread_mutex_unlock(&d->stop_mtx);
	return (v);
}

void	set_stop(t_data *d)
{
	pthread_mutex_lock(&d->stop_mtx);
	d->stop = 1;
	pthread_mutex_unlock(&d->stop_mtx);
}

void	wait_seat(t_data *d)
{
	while (!should_stop(d))
	{
		pthread_mutex_lock(&d->seat_mtx);
		if (d->seats > 0)
		{
			d->seats--;
			pthread_mutex_unlock(&d->seat_mtx);
			return ;
		}
		pthread_mutex_unlock(&d->seat_mtx);
		usleep(200);
	}
}

void	leave_seat(t_data *d)
{
	pthread_mutex_lock(&d->seat_mtx);
	d->seats++;
	pthread_mutex_unlock(&d->seat_mtx);
}

void	print_action(t_philo *p, const char *msg)
{
	long	ts;

	if (should_stop(p->data))
		return ;
	pthread_mutex_lock(&p->data->print_mtx);
	if (!should_stop(p->data))
	{
		ts = now_ms() - p->data->start_ms;
		printf("%ld %d %s\n", ts, p->id, msg);
	}
	pthread_mutex_unlock(&p->data->print_mtx);
}
