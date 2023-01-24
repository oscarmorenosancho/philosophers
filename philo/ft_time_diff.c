/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_diff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:38:03 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/24 12:48:58 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	ft_time_diff(t_timestamp *ref, t_timestamp *time)
{
	int		ret;
	time_t	sec;
	time_t	usec;

	ret = 0;
	if (ref && time && time->tv_sec > ref->tv_sec)
	{
		sec = time->tv_sec - ref->tv_sec;
		usec = time->tv_usec - ref->tv_usec;
	}
	return (ret);
}