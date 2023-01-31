/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:39:53 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/31 14:07:21 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_args(t_program_data *data, int argc, char **argv)
{
	if (data)
	{
		data->args.philo_nbr = ft_atoi(argv[1]);
		data->args.time_to_die = ft_atoi(argv[2]);
		data->args.time_to_eat = ft_atoi(argv[3]);
		data->args.time_to_sleep = ft_atoi(argv[4]);
		data->args.times_must_eat = 0;
		if (argc == 6)
			data->args.times_must_eat \
				= ft_atoi(argv[5]);
	}
	return (data->args.philo_nbr > 0 && data->args.time_to_die > 0 \
		&& data->args.time_to_eat > 0 && data->args.time_to_sleep > 0 \
		&& data->args.times_must_eat >= 0);
}
