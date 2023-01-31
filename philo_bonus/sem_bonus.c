/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:14:17 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/31 17:21:17 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_create_forks_sem(t_program_data *data)
{
	char	*err_msg;

	data->sem_forks = sem_open("/philo_forks_sem", O_CREAT, \
		S_IRWXU | S_IRWXG | S_IRWXO, data->args.philo_nbr);
	if (data->sem_forks == SEM_FAILED)
	{
		data->sem_forks = NULL;
		err_msg = "Error\n";
		write(2, err_msg, ft_strlen(err_msg));
		err_msg = "open forks semaphore failed\n"; 
		write(2, err_msg, ft_strlen(err_msg));
	}
}

void	ft_destroy_forks_sem(t_program_data *data)
{
	char	*err_msg;
	int		sc_ret;
	int		su_ret;

	sc_ret = 0;
	if (data->sem_forks)
		sc_ret = sem_close(data->sem_forks);
	if (sc_ret != 0)
	{
		err_msg = "Error\n";
		write(2, err_msg, ft_strlen(err_msg));
		err_msg = "close forks semaphore failed\n";
		write(2, err_msg, ft_strlen(err_msg));
		return ;
	}
	su_ret = sem_unlink("/philo_forks_sem");
	if (su_ret)
	{
		err_msg = "Error\n";
		write(2, err_msg, ft_strlen(err_msg));
		err_msg = "unlink forks semaphore failed\n";
		write(2, err_msg, ft_strlen(err_msg));
		return ;
	}
}

void	ft_create_print_sem(t_program_data *data)
{
	char	*err_msg;

	data->sem_print = sem_open("/philo_print_sem", O_CREAT, \
		S_IRWXU | S_IRWXG | S_IRWXO, 1);
	if (data->sem_print == SEM_FAILED)
	{
		data->sem_print = NULL;
		err_msg = "Error\n";
		write(2, err_msg, ft_strlen(err_msg));
		err_msg = "open forks semaphore failed\n"; 
		write(2, err_msg, ft_strlen(err_msg));
	}
}

void	ft_destroy_print_sem(t_program_data *data)
{
	char	*err_msg;
	int		sc_ret;
	int		su_ret;

	sc_ret = 0;
	if (data->sem_print)
		sc_ret = sem_close(data->sem_print);
	if (sc_ret != 0)
	{
		err_msg = "Error\n";
		write(2, err_msg, ft_strlen(err_msg));
		err_msg = "close print semaphore failed\n";
		write(2, err_msg, ft_strlen(err_msg));
		return ;
	}
	su_ret = sem_unlink("/philo_print_sem");
	if (su_ret)
	{
		err_msg = "Error\n";
		write(2, err_msg, ft_strlen(err_msg));
		err_msg = "unlink print semaphore failed\n";
		write(2, err_msg, ft_strlen(err_msg));
		return ;
	}
}
