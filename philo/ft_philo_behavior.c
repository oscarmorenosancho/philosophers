/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_behavior.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:17:45 by omoreno-          #+#    #+#             */
/*   Updated: 2023/02/02 15:28:29 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
