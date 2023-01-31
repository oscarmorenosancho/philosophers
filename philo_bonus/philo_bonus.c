/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:38:13 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/31 17:56:45 by omoreno-         ###   ########.fr       */
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
	err_msg = "what will mean that the program only ends when one died\n";
	write(2, err_msg, ft_strlen(err_msg));
}

static void	ft_create_philos(t_program_data *data, pid_t *fork_ret)
{
	int				i;

	i = 0;
	while (i < data->args.philo_nbr && (*fork_ret > 0 || i == 0))
	{
		*fork_ret = fork();
		i++;
	}
	if (*fork_ret == 0)
	{
		printf("fork return %d at iter %d\n", *fork_ret, i);
		data->exit_flag = 0;
		data->philo.id = i;
		data->philo.done = 0;
		data->philo.ch_status_ts = data->initial_ts;
		data->philo.eat_ts = data->initial_ts;
		if (i % 2)
			data->philo.status = stat_sleeping;
		else
			data->philo.status = stat_thinking;
		data->philo.eat_count = 0;
		data->philo.forks_taken = 0;
		ft_print_event(data, &data->initial_ts, "init philo\n");
		ft_philo_behavior(data);
	}
	else if (*fork_ret > 0)
		printf("fork return %d at iter %d\n", *fork_ret, i);
}

static void	ft_wait_for_philos(t_program_data *data, pid_t *fork_ret)
{
	pid_t			wp_ret;
	int				wp_status;

	(void)data;
	if (*fork_ret != 0)
	{
		wp_ret = waitpid(0, &wp_status, WCONTINUED);
	}
}

int	main(int argc, char **argv)
{
	t_program_data	data;
	pid_t			fork_ret;

	fork_ret = 0;
	memset(&data, 0, sizeof(t_program_data));
	if (argc == 5 || argc == 6)
	{
		if (ft_take_args(&data, argc, argv))
		{
			ft_get_timestamp(&data.initial_ts);
			ft_create_print_sem(&data);
			ft_create_forks_sem(&data);
			ft_create_philos(&data, &fork_ret);
			if (fork_ret == 0)
				return (0);
			ft_wait_for_philos(&data, &fork_ret);
			ft_destroy_forks_sem(&data);
			ft_destroy_print_sem(&data);
		}
		else
			ft_print_usage_help();
	}
	else
		ft_print_usage_help();
	return (0);
}
