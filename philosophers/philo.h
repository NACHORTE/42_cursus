/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:36:10 by iortega-          #+#    #+#             */
/*   Updated: 2023/07/27 17:08:04 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_X
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

int	ft_atoi(const char *str);

typedef struct s_shared {
	int				*forks;
	pthread_mutex_t	*shared_mutex;
}	t_shared;

typedef struct s_params {
	int			n_philos;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			id;
	int			reset;
	struct timeval	time;
	t_shared	*shared_data;
}	t_params;

#endif