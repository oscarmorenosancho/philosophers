/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:38:13 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/26 14:23:17 by omoreno-         ###   ########.fr       */
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

static void	ft_print_arguments(t_philo_args *args)
{
	printf("Philosophers number: %d\n", args->philo_nbr);
	printf("Time to die: %dms\n", args->time_to_die);
	printf("Time to eat: %dms\n", args->time_to_eat);
	printf("Time to sleep: %dms\n", args->time_to_sleep);
	printf("Times must eat: %d\n", \
		args->number_of_times_each_philosopher_must_eat);
}

int	main(int argc, char **argv)
{
	t_program_data	data;

	memset(&data, 0, sizeof(t_program_data));
	if (argc == 5 || argc == 6)
	{
		ft_take_args(&data, argc, argv);
		ft_print_arguments(&data.args);
		ft_init_forks(&data);
		ft_init_philo(&data);
		ft_create_threads(&data);
		ft_join_threads(&data);
		ft_destroy_threads(&data);
		ft_delete_philo(&data);
		ft_delete_forks(&data);
	}
	else
		ft_print_usage_help();
	return (0);
}
