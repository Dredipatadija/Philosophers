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

	long	start_time;
	int		dieorfull;
	t_fork	*forks;
	t_philo	*philos;
}	t_data;

int		main(int ac, char **av);
void	ft_parsearg(char **av);
int		ft_checklen(char *arg);
int		ft_checkint(char *arg);
void	ft_arg_data(t_data *data, int ac, char **av);
void	ft_mutex_handle(t_mutex *mtx, int op);
void	ft_thread_handle(t_thread *thread, int op,
			void *(*ft_start)(void *), t_data *data);
void	ft_error1(char *str);