/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_behavior_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:58:12 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/31 18:01:51 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_philo_sleeps(t_program_data *data)
{
	t_philo_info	*pi;
	t_timestamp		ts;
	time_t			et;

	pi = &data->philo;
	if (!ft_update_dead(data, &ts))
	{
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		if (et >= data->args.time_to_sleep)
		{
			ft_print_event(data, &ts, "is thinking");
			pi->status = stat_thinking;
			pi->ch_status_ts = ts;
		}
	}
	return ;
}

void	ft_philo_thinks(t_program_data *data)
{
	t_philo_info	*pi;
	t_timestamp		ts;
	time_t			et;
	int				sw_ret;	

	pi = &data->philo;
	if (!ft_update_dead(data, &ts))
	{
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		if (! pi->forks_taken)
		{
			ft_print_event(data, &ts, "is going to take a fork");
			sw_ret = sem_wait(data->sem_forks);
			if (sw_ret)
				perror("sem wait failed\n");
			ft_print_event(data, &ts, "has taken a fork");
			if (data->args.philo_nbr > 1)
			{
				ft_print_event(data, &ts, "is going to take a fork");
				sem_wait(data->sem_forks);
				ft_print_event(data, &ts, "has taken a fork");
				ft_print_event(data, &ts, "is eating");
				pi->status = stat_eating;
				pi->ch_status_ts = ts;
				pi->eat_count++;
			}
			pi->forks_taken = 1;
		}
	}
	return ;
}

static void	ft_release_forks(t_program_data *data)
{
	t_philo_info	*pi;

	pi = &data->philo;
	if (pi->forks_taken)
	{
		sem_post(data->sem_forks);
		if (data->args.philo_nbr > 1)
			sem_post(data->sem_forks);
		pi->forks_taken = 0;
	}
}

void	ft_philo_eats(t_program_data *data)
{
	t_philo_info	*pi;
	t_timestamp		ts;
	time_t			et;

	pi = &data->philo;
	if (!ft_update_dead(data, &ts))
	{
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		if (et >= data->args.time_to_eat)
		{
			ft_release_forks(data);
			ft_print_event(data, &ts, "is sleeping");
			pi->status = stat_sleeping;
			pi->ch_status_ts = ts;
			pi->eat_ts = ts;
			if (data->args.times_must_eat > 0 \
				&& pi->eat_count >= data->args.times_must_eat)
				pi->done = 1;
		}
	}
	else
		ft_release_forks(data);
	return ;
}

void	ft_philo_behavior(t_program_data *data)
{
	void			*ret;
	t_philo_info	*pi;

	ret = NULL;
	pi = &data->philo;
	while (pi->status != stat_dead && !(data->exit_flag) && !pi->done)
	{
		if (pi->status == stat_sleeping)
			ft_philo_sleeps(data);
		else if (pi->status == stat_thinking)
			ft_philo_thinks(data);
		else if (pi->status == stat_eating)
			ft_philo_eats(data);
		else if (pi->status == stat_dead)
			return ;
		else
			pi->status = stat_dead;
		usleep(10);
	}
	return ;
}
