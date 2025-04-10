#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthreatd.h>
#include <sys/time.h>
#include <limits.h>

typedef struct s_philo
{
	int			philo_id;
	t_fork		*left_fork;
	t_fork		*right_fork;
	int			n_meals;
	int			full;
	long		last_meal;
	pthread_t	thread_id;
	t_data		*data;
}	t_philo;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

typedef struct s_data
{
	long	num_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	min_meals;
	long	num_meals;
	long	start_time;
	int		dieorfull;
	t_fork	*forks;
	t_philo	*philos;
}	t_data;
