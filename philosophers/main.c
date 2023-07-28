/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:10:09 by iortega-          #+#    #+#             */
/*   Updated: 2023/07/27 17:32:01 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*left_to_die(void *params)
{
	t_params		*data;
	struct timeval	time_1;
	struct timeval	time_2;
	long			diff;
	int				dead;

	data = (t_params *)params;
	dead = 0;
	while (dead == 0)
	{
		gettimeofday(&time_1, NULL);
		data->reset = 0;
		while (data->reset == 0 && dead == 0)
		{
			gettimeofday(&time_2, NULL);
			diff = time_2.tv_usec - time_1.tv_usec;
			if (diff >= data->t_die)
			{
				printf("%ld %d\n", diff, data->id);
				dead = 1;
			}
		}
	}
	if (dead == 1)
		printf("%d has died.\n", data->id);
}

void	*alive(void *params)
{
	t_params	*data; 								//tenemos shared data a la que acceden todos y params que son los privados.
	t_shared	*shared_data;
	int			id;
	pthread_t	counter;	
	
	data = (t_params *)params;
	shared_data = data->shared_data;
	id = data->id;
	pthread_create(&counter, NULL, left_to_die, data);
	/*printf("%d: Estoy vivo!\n", id);
	for(int i = 0; i<6; i++)
	{
		printf("%d: leyendo tenedor %d = %d\n",id, i, shared_data->forks[i]);
	}*/
	for(int i = 0;i < 3; i++)								//cada filosofo intenta coger los dos tenedores y los bloquea, come y los desbloquea
	{
		pthread_mutex_lock(&shared_data->shared_mutex[id-1]);
		shared_data->forks[id-1] = id;
		gettimeofday(&data->time, NULL);
		printf("%ldms %d has taken a fork.\n", data->time.tv_usec, id);
		if (id == data->n_philos)
			pthread_mutex_lock(&shared_data->shared_mutex[0]);
		else
			pthread_mutex_lock(&shared_data->shared_mutex[id]);
		gettimeofday(&data->time, NULL);
		printf("%ldms %d has taken a fork.\n", data->time.tv_usec, id);
		shared_data->forks[id] = id;
		data->reset = 1;
		gettimeofday(&data->time, NULL);
		printf("%ldms %d is eating.\n", data->time.tv_usec, id);
		usleep(data->t_eat);
		/*gettimeofday(&data->time, NULL);
		printf("%ldms %d has eaten.\n", data->time.tv_usec, id);*/
		pthread_mutex_unlock(&shared_data->shared_mutex[id-1]);
		if (id == data->n_philos)
			pthread_mutex_unlock(&shared_data->shared_mutex[0]);
		else
			pthread_mutex_unlock(&shared_data->shared_mutex[id]);
		data->reset = 1;
		gettimeofday(&data->time, NULL);
		printf("%ldms %d is sleeping.\n", data->time.tv_usec, id);
		usleep(data->t_sleep);
		
	}
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_params	*philos_data;
	pthread_t	*philos_thread;	
	int			i;
	t_shared	shared_data;

	if (argc != 5)
		return (0);
	params.n_philos = ft_atoi(argv[1]);
	params.t_die = ft_atoi(argv[2]);
	params.t_eat = ft_atoi(argv[3]);
	params.t_sleep = ft_atoi(argv[4]);
	if (params.n_philos <= 0)
	{
		printf("Please enter a correct number of philosophers.\n");
		return (0);
	}
	philos_thread = malloc(sizeof(pthread_t) * params.n_philos);			//primero reservamos memoria para todos los hilos
	philos_data = malloc(sizeof(t_params) * params.n_philos);				//reservamos memoria para los datos privados
	params.shared_data = &shared_data;										//apuntamos a la misma region de memoria en todos los shared data
	shared_data.forks = malloc(sizeof(int) * params.n_philos);				//creamos todos los tenedores y un mutex para cada uno
	shared_data.shared_mutex = malloc(sizeof(pthread_mutex_t) * params.n_philos);
	i = 0;
	while (i < params.n_philos)
	{
		shared_data.forks[i] = 1;
		pthread_mutex_init(&shared_data.shared_mutex[i], NULL);
		i++;
	}
	
	i = 0;
	while (i < params.n_philos)
	{
		params.id = i + 1;
		params.reset = 0;
		philos_data[i] = params;
		pthread_create(&philos_thread[i], NULL, alive, &philos_data[i]);
		i++;
	}
	while (i > 0)
	{
		i--;
		pthread_join(philos_thread[i], NULL);
	}
	return (0);
}
