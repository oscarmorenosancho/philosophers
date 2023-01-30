/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:38:13 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/30 13:22:24 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_print_usage_help(void)
{
	char	*err_msg;

	err_msg = "Error\n";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "Usage: ./philo ";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "<number_of_philosophers> <time_to_die> ";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "<time_to_eat> <time_to_sleep> ";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "[number_of_times_each_philosopher_must_eat]\n";
	write(2, err_msg, ft_strlen(err_msg));
}

int	main(int argc, char **argv)
{
	t_program_data	data;

	memset(&data, 0, sizeof(t_program_data));
	if (argc == 5 || argc == 6)
	{
		ft_take_args(&data, argc, argv);
		ft_get_timestamp(&data.initial_ts);
		ft_init_print_mutex(&data);
		ft_init_forks(&data);
		ft_init_philo(&data);
		ft_create_threads(&data);
		ft_join_threads(&data);
		ft_destroy_threads(&data);
		ft_delete_philo(&data);
		ft_delete_forks(&data);
		ft_delete_print_mutex(&data);
	}
	else
		ft_print_usage_help();
	return (0);
}
