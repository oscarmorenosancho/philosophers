/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_behavior.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:17:45 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/01 14:29:29 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_sleeps(t_philo_info *pi)
{
	t_timestamp		ts;
	time_t			et;

	if (!ft_update_dead(pi, &ts))
	{
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		if (et >= pi->args->time_to_sleep)
		{
			ft_print_event(pi, &ts, "is thinking");
			pi->status = stat_thinking;
			pi->ch_status_ts = ts;
		}
	}
	return ;
}

void	ft_philo_thinks(t_philo_info *pi)
{
	t_timestamp		ts;
	time_t			et;
	int				ml_ret;

	if (!ft_update_dead(pi, &ts))
	{
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		if (! pi->forks_taken)
		{
			ml_ret = pthread_mutex_lock(pi->left_fork_mutex);
			ft_print_event(pi, &ts, "has taken a fork");
			if (pi->left_fork_mutex != pi->right_fork_mutex)
			{
				ml_ret = pthread_mutex_lock(pi->right_fork_mutex);
				ft_get_timestamp(&ts);
				ft_print_event(pi, &ts, "has taken a fork");
				ft_print_event(pi, &ts, "is eating");
				pi->status = stat_eating;
				pi->ch_status_ts = ts;
				pi->eat_count++;
			}
			pi->forks_taken = 1;
		}
	}
	return ;
}

static void	ft_release_forks(t_philo_info *pi)
{
	int				mu_ret;

	if (pi->forks_taken)
	{
		mu_ret = pthread_mutex_unlock(pi->left_fork_mutex);
		if (pi->left_fork_mutex != pi->right_fork_mutex)
			mu_ret = pthread_mutex_unlock(pi->right_fork_mutex);
		pi->forks_taken = 0;
	}
}

void	ft_philo_eats(t_philo_info *pi)
{
	t_timestamp		ts;
	time_t			et;

	if (!ft_update_dead(pi, &ts))
	{
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		if (et >= pi->args->time_to_eat)
		{
			ft_release_forks(pi);
			ft_print_event(pi, &ts, "is sleeping");
			pi->status = stat_sleeping;
			pi->ch_status_ts = ts;
			pi->eat_ts = ts;
			if (pi->args->times_must_eat > 0 \
				&& pi->eat_count >= pi->args->times_must_eat)
				pi->done = 1;
		}
	}
	else
		ft_release_forks(pi);
	return ;
}

void	*ft_philo_behavior(void *arg)
{
	void			*ret;
	t_philo_info	*pi;

	pi = arg;
	ret = NULL;
	while (pi->status != stat_dead && pi->exit_flag \
			&& !*(pi->exit_flag) && !pi->done)
	{
		if (pi->status == stat_sleeping)
			ft_philo_sleeps(pi);
		else if (pi->status == stat_thinking)
			ft_philo_thinks(pi);
		else if (pi->status == stat_eating)
			ft_philo_eats(pi);
		else if (pi->status == stat_dead)
			return (ret);
		else
			pi->status = stat_dead;
		usleep(10);
	}
	return (ret);
}
