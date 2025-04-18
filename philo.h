#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthreatd.h>
#include <sys/time.h>
#include <limits.h>

typedef struct s_philo
{
	int			philo_id;
	t_fork		*first_fork;
	t_fork		*second_fork;
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
	long			num_phi;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			min_meals;
	int				allready;
	long			start_time;
	int				dieorfull;
	t_fork			*forks;
	t_philo			*philos;
	pthread_mutex_t	start_mtx;
}	t_data;
