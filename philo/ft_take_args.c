/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:39:53 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/15 19:33:11 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_args(t_program_data *data, int argc, char **argv)
{
	if (data)
	{
		if (ft_check_n_get_argument(argv[1], &data->args.philo_nbr) \
			&& ft_check_n_get_argument(argv[2], &data->args.time_to_die) \
			&& ft_check_n_get_argument(argv[3], &data->args.time_to_eat) \
			&& ft_check_n_get_argument(argv[4], &data->args.time_to_sleep))
		{
			printf("Nbr philo:%d\n", data->args.philo_nbr);
			printf("time_to_die:%d\n", data->args.time_to_die);
			printf("time_to_eat:%d\n", data->args.time_to_eat);
			printf("time_to_sleep:%d\n", data->args.time_to_sleep);
			return (0);
		}
		data->args.times_must_eat = 0;
		if (argc == 6)
			if (ft_check_n_get_argument(argv[5], &data->args.times_must_eat))
				return (0);
	}
	return (data->args.philo_nbr > 0 && data->args.time_to_die > 0 \
		&& data->args.time_to_eat > 0 && data->args.time_to_sleep > 0 \
		&& data->args.times_must_eat >= 0);
}
