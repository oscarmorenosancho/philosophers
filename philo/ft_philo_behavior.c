/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_behavior.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:17:45 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/15 12:35:47 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_behavior(void *arg)
{
	t_philo_info	*pi;
	t_timestamp		ts;

	pi = arg;
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
			return (NULL);
		else
			pi->status = stat_dead;
		usleep(10);
	}
	ft_release_forks(pi);
	while (pi->exit_flag && !*(pi->exit_flag) \
			&& pi->done_cntdwn && *pi->done_cntdwn > 0 \
			&& !ft_update_dead(pi, &ts))
		usleep(10);
	ft_release_forks(pi);
	ft_print_event(pi, "has finished the thread");
	return (NULL);
}
