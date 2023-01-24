/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:05:37 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/24 12:18:48 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum e_philo_status{
	stat_dead,
	stat_thinking,
	stat_eating,
	stat_sleeping
}	t_philo_status;

typedef struct timeval	t_timestamp;

typedef struct s_philo_args
{
	int		philo_nbr;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
}	t_philo_args;

typedef struct s_philo_info
{
	int				id;
	int				*exit_flag;
	t_philo_status	status;
	t_timestamp		eat_ts;
	t_timestamp		ch_status_ts;
	t_philo_args	*args;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
}	t_philo_info;

typedef struct s_program_data
{	
	int				exit_flag;
	t_philo_args	args;
	pthread_t		**threads;
	pthread_mutex_t	**forks;
	t_philo_info	**philo;
}	t_program_data;

int		ft_strlen(char *s);
void	ft_take_args(t_program_data *data, int argc, char **argv);
void	ft_init_forks(t_program_data *data);
void	ft_delete_forks(t_program_data *data);
void	ft_init_philo(t_program_data *data);
void	ft_delete_philo(t_program_data *data);
void	*ft_philo_behavior(void *arg);
void	ft_create_threads(t_program_data *data);
void	ft_join_threads(t_program_data *data);
void	ft_destroy_threads(t_program_data *data);
#endif