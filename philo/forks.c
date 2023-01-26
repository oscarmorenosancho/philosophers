/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:30:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/26 14:25:11 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_forks(t_program_data *data)
{
	int	i;

	if (data)
	{
		data->forks = malloc(sizeof(pthread_mutex_t *) \
			* data->args.philo_nbr);
		if (data->forks)
		{
			memset(data->forks, 0, \
				sizeof(pthread_mutex_t *) * data->args.philo_nbr);
			i = 0;
			while (i < data->args.philo_nbr)
			{
				data->forks[i] = malloc(sizeof(pthread_mutex_t));
				if (data->forks[i])
				{
					pthread_mutex_init(data->forks[i], NULL);
				}
				i++;
			}
		}
	}
}

void	ft_delete_forks(t_program_data *data)
{
	int	i;

	if (data && data->forks)
	{
		i = 0;
		while (i < data->args.philo_nbr)
		{
			if (data->forks[i])
			{
				pthread_mutex_destroy(data->forks[i]);
				free(data->forks[i]);
			}
			i++;
		}
		free(data->forks);
	}
}
