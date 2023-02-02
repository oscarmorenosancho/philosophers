/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_eats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:26:30 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/02 15:50:06 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_release_forks(t_philo_info *pi)
{
	int				mu_ret;

	if (pi->forks_taken == 2)
	{
		mu_ret = pthread_mutex_unlock(pi->left_fork_mutex);
		pi->forks_taken--;
	}
	if (pi->left_fork_mutex != pi->right_fork_mutex && pi->forks_taken == 1)
	{
		mu_ret = pthread_mutex_unlock(pi->right_fork_mutex);
		pi->forks_taken--;
	}
}

static void	ft_update_done_status(t_philo_info *pi)
{
	pi->done = 1;
	if (pi->done_cntdwn && pi->done_cntdwn_mutex)
	{
		pthread_mutex_lock(pi->done_cntdwn_mutex);
		(*pi->done_cntdwn)--;
		pthread_mutex_unlock(pi->done_cntdwn_mutex);
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
			ft_print_event(pi, "is sleeping");
			pi->status = stat_sleeping;
			pi->ch_status_ts = ts;
			if (pi->args->times_must_eat > 0 \
				&& pi->eat_count >= pi->args->times_must_eat)
				ft_update_done_status(pi);
		}
	}
	else
		ft_release_forks(pi);
}
