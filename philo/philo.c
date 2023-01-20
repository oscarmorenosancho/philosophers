/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:38:13 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/19 16:08:18 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char			*err_msg;
	t_program_data	*data;

	if (argc == 5)
	{
		;
	}
	else
	{
		err_msg = "Error\nUsage: ./philo <nb philo> <time_to_die> <time_to_eat> <time_to_sleep>\n"
		write(2, err_msg, ft_strlen(err_msg));
	}
	return (0);
}