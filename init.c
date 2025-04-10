#include "philo.h"

void	ft_arg_data(t_data *data, int ac, char **av)
{
	data->num_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->min_meals = ft_atoi(av[5]);
	else
		data->min_meals = -1;
	data->dieorfull = 0;
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
		ft_error1("Error: malloc failed for philosopher array\n");
}
