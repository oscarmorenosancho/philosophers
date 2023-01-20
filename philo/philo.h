/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:05:37 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/19 16:05:51 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

typedef enum e_philo_status{
	stat_dead,
	stat_thinking,
	stat_eating,
	stat_sleeping
}	t_philo_status;

typedef struct s_philo_info
{
	int				id;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	t_philo_status	status;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
}	t_philo_info;

typedef struct s_program_data
{
	int				philo_nbr;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	pthread_t		**threads;
	pthread_mutex_t	**forks;
	t_philo_info	**philo;
}	t_program_data;