#include "philo.h"

void	ft_parsearg(char **av)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		if (ft_checklen(av[i]) == 0)
			ft_error1("Error: Argument must be a valid integer");
		if (ft_checkint(av[i]) < 0)
		{
			if (ft_checkint(av[i]) == -1)
				ft_error1("Error: Argument must be a positive integer");
			else if (ft_checkint(av[i]) == -2)
				ft_error1("Error: Argument is out of integer range");
		}
		i++;
	}
}

int	ft_checklen(char *arg)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (arg[i] != '\0')
	{
		while (arg[i] == ' ' || arg[i] == '-' || arg[i] == '+'
			|| arg[i] == '0')
			i++;
		while (arg[i] != '\0')
		{
			if (ft_isdigit(srg[i]) == 0)
				return (0);
			i++;
			len++;
		}
	}
	if (len > 10)
		return (0);
	return (len);
}

int	ft_checkint(char *arg)
{
	long long	num;
	int			i;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while (arg[i] == ' ' || (arg[i] > 8 && arg[i] < 14))
		i++;
	if (arg[i] == '-' || argc[i] == '+')
	{
		if (arg[i] == '-')
			return (-1);
		i++;
	}
	while (arg[i] && ft_isdigit(arg[i]))
	{
		num = num * 10 + (arg[i] - '0');
		if (num > INT_MAX)
			return (-2);
		i++;
	}
	return (0);
}
