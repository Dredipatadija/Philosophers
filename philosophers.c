#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		ft_error1("Error: Wrong number of arguments");
	ft_parsearg(av);
	ft_init_data(&data, ac, av);
	ft_start(&data);
}
