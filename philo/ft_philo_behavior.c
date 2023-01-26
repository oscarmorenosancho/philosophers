/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_behavior.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:17:45 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/26 14:46:25 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_update_dead(t_philo_info *pi, t_timestamp *ts)
{
	int				gtod_ret;
	int				dead;
	time_t			et;

	gtod_ret = gettimeofday(ts, NULL);
	et = ft_time_diff(&pi->eat_ts, ts);
	dead = (et >= pi->args->time_to_die);
	if (dead && pi->status != stat_dead)
	{
		ft_print_event(pi, ts, "died");
		pi->status = stat_dead;
		pi->ch_status_ts = *ts;
		if (pi->exit_flag)
			*(pi->exit_flag) = 1;
	}
	return (dead);
}

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

	if (!ft_update_dead(pi, &ts))
	{
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		//lock left fork
		ft_print_event(pi, &ts, "has taken a fork");
		//lock right fork
		ft_print_event(pi, &ts, "has taken a fork");
		ft_print_event(pi, &ts, "is eating");
		pi->status = stat_eating;
		pi->ch_status_ts = ts;
	}
	return ;
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
			//unlock left fork
			//unlock right fork

			ft_print_event(pi, &ts, "is sleeping");
			pi->status = stat_sleeping;
			pi->ch_status_ts = ts;
		}
	}
	return ;
}

void	*ft_philo_behavior(void *arg)
{
	void			*ret;
	t_philo_info	*pi;

	pi = arg;
	ret = NULL;
	while (pi->status != stat_dead && pi->exit_flag && !*(pi->exit_flag))
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
