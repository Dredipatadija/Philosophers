void	ft_start(t_data *data)
{
	int	i;

	i = 0;
	if (data->min_meals == 0)
		return ;
	if (data->num_phi == 1)
		TO DO;
	else
	{
		while (i < data->num_phi)
		ft_thread_handle(&data->philos[i].thread.id, 5, ft_routine, data)
	}
}
