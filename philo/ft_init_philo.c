/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:47:22 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/20 16:58:26 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_n_philo(t_program_data *data, int n, const t_timestamp *ts)
{
	data->philo[n] = malloc(sizeof(t_philo_info));
	if (data->philo[n])
	{
		memset(data->philo[n], 0, sizeof(t_philo_info));
		data->philo[n]->id = n + 1;
		data->philo[n]->args = &data->args;
		data->philo[n]->eat_ts = *ts;
		data->philo[n]->ch_status_ts = *ts;
		if (n % 2)
			data->philo[n]->status = stat_thinking;
		else
			data->philo[n]->status = stat_sleeping;
		data->philo[n]->left_fork_mutex = data->forks[n];
		data->philo[n]->right_fork_mutex = \
			data->forks[(n + 1) % data->args.philo_nbr];
	}
}

void	ft_init_philo(t_program_data *data)
{
	int				i;
	t_timestamp		ts;
	int				gtod_ret;

	if (data)
	{
		gtod_ret = gettimeofday(&ts, NULL);
		data->philo = malloc (sizeof(t_philo_info *) * data->args.philo_nbr);
		if (data->philo)
		{
			memset(data->philo, 0, \
				sizeof(t_philo_info *) * data->args.philo_nbr);
			i = 0;
			while (i < data->args.philo_nbr)
			{
				ft_init_n_philo(data, i, &ts);
				i++;
			}
		}
	}	
}

void	ft_delete_philo(t_program_data *data)
{
	int	i;

	if (data && data->philo)
	{
		i = 0;
		while (i < data->args.philo_nbr)
		{
			if (data->philo[i])
				free(data->philo[i]);
			i++;
		}
		free(data->philo);
	}	
}
