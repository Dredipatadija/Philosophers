#include "philo.h"

void	ft_init_data(t_data *data, int ac, char **av)
{
	t_philo	philos;
	t_fork	forks;

	data->num_phi = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->min_meals = ft_atoi(av[5]);
	else
		data->min_meals = -1;
	data->dieorfull = 0;
	data->allready = 0;
	data->philos = &philos;
	data->forks = &forks;
	ft_init_forks(data);
	ft_init_philos(data);
	ft_mutex_handle(&data->start_mtx, 3);
}

void	ft_init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_phi)
	{
		data->forks[i].fork_id = i;
		ft_mutex_handle(&data->forks[i].fork, 3);
		i++;
	}
}

void	ft_init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_phi)
	{
		data->philos[i].philo_id = i + 1;
		data->philos[i].n_meals = 0;
		data->philos[i].full = 0;
		data->philos[i].first_fork = &data->forks[i];
		data->philos[i].second_fork = &data->forks[(i + 1) % data->num_phi];
		if (data->philo[i].philo_id % 2 == 1)
		{
			data->philo[i].first_fork = &data->forks[i];
			data->philo[i].second_fork = &data->forks[(i + 1) % data->num_phi];
		}
	}
}
