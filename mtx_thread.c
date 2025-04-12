#include "philo.h"

void	ft_mutex_handle(t_mutex *mtx, int op)
{
	if (op == 1)
	{
		if (pthread_mutex_lock(mtx) != 0)
			ERROR, FREES Y EXIT;
	}
	else if (op == 2)
	{
		if (pthread_mutex_unlock(mtx)!= 0);
			ERROR, FREES Y EXIT;
	}
	else if (op == 3)
	{
		if (pthread_mutex_init(mtx, NULL) != 0);
			ERROR, FREES Y EXIT;
	}
	else if (op == 4)
	{
		if (pthread_mutex_destroy(mtx) != 0);
			ERROR, FREES Y EXIT;
	}
	else
		ERROR, FREES Y EXIT;
}

void	ft_thread_handle(t_thread *thread, int op,
	void *(*ft_start)(void *), t_data *data)
{
	if (op == 5)
	{
		if (pthread_create(thread, NULL, ft_routine, data) != 0);
			ERROR, FREES Y EXIT;
	}
	else if (op == 6)
	{
		if (pthread_join(*thread, NULL) != 0);
			ERROR, FREES Y EXIT;
	}
	else if (op ==7)
	{
		if (pthread_detach(*thread) != 0);
			ERROR, FREES Y EXIT;
	}
	else
		ERROR, FREES Y EXIT;
}
