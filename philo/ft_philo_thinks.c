/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_thinks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:26:33 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/15 12:23:23 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_philo_thinks_with_no_fork(t_philo_info *pi)
{
	int	ml_ret;

	ml_ret = pthread_mutex_lock(pi->left_fork_mutex);
	ft_print_event(pi, "has taken a fork: the first one");
	pi->forks_taken++;
}

static void	ft_philo_thinks_with_one_fork(t_philo_info *pi)
{
	t_timestamp		ts;
	int				ml_ret;

	ml_ret = pthread_mutex_lock(pi->right_fork_mutex);
	ft_print_event(pi, "has taken a fork: the second one");
	ft_print_event(pi, "is eating");
	pi->status = stat_eating;
	ft_get_timestamp(&ts);
	pi->ch_status_ts = ts;
	pi->eat_ts = ts;
	pi->eat_count++;
	pi->forks_taken++;
}

void	ft_philo_thinks(t_philo_info *pi)
{
	t_timestamp		ts;
	time_t			et;

	if (!ft_update_dead(pi, &ts) && pi->exit_flag && !*(pi->exit_flag))
	{
		et = ft_time_diff(&pi->ch_status_ts, &ts);
		if (pi->forks_taken == 0 && pi->exit_flag && !*(pi->exit_flag))
			ft_philo_thinks_with_no_fork(pi);
		if (!ft_update_dead(pi, &ts) && \
				pi->left_fork_mutex != pi->right_fork_mutex \
				&& pi->forks_taken == 1 && pi->exit_flag && !*(pi->exit_flag))
			ft_philo_thinks_with_one_fork(pi);
	}
	if (pi->exit_flag && *(pi->exit_flag))
		ft_release_forks(pi);
}
