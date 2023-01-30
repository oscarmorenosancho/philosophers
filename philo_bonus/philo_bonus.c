/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:38:13 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/30 16:24:45 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	err_msg = "All arguments must be positive\n";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "number_of_times_each_philosopher_must_eat can be 0\n";
	write(2, err_msg, ft_strlen(err_msg));
	err_msg = "what will mean that the program only ends when there's one died\n";
	write(2, err_msg, ft_strlen(err_msg));
}

int	main(int argc, char **argv)
{
	t_program_data	data;
	int				i;
	pid_t			fork_ret;

	fork_ret = 0;
	memset(&data, 0, sizeof(t_program_data));
	if (argc == 5 || argc == 6)
	{
		if (ft_take_args(&data, argc, argv))
		{
			ft_get_timestamp(&data.initial_ts);
			i = 1;
			while (i <= data.args.philo_nbr && fork_ret > 0)
			{
				fork_ret = fork();
				i++;
			}
			if (fork_ret == 0)
			{
				data.philo.id = i;
			}
			//ft_init_print_mutex(&data);
			//ft_init_forks(&data);
			//ft_init_philo(&data);

			//ft_delete_philo(&data);
			//ft_delete_forks(&data);
			//ft_delete_print_mutex(&data);
		}
		else
			ft_print_usage_help();
	}
	else
		ft_print_usage_help();
	return (0);
}
