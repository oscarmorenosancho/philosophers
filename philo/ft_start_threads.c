/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:44:38 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/20 16:34:35 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_n_thread(t_program_data *data, int n)
{
	int				thc_ret;
	pthread_attr_t	attr;

	thc_ret = pthread_create(data->threads[n], &attr, \
		&ft_philo_behavior, data->philo[n]);
}

void	ft_start_threads(t_program_data *data)
{
	int	i;

	if (data)
	{
		data->threads = malloc(sizeof(pthread_t *) * data->args.philo_nbr);
		if (data->threads)
		{
			memset(data->threads, 0, \
				sizeof(pthread_t *) * data->args.philo_nbr);
			i = 0;
			while (i < data->args.philo_nbr)
			{
				data->threads[i] = malloc(sizeof(pthread_t));
				if (data->threads[i])
					ft_start_n_thread(data, i);
				i++;
			}
		}
	}	
}


