/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:27:01 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/16 17:27:56 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philo.h"

void init_info(t_info *info, char **argv)
{
	struct timeval  tv;
	
	info->dead_flag = EVERYONE_ALIVE;
	pthread_mutex_init(&info->death_mutex_id, NULL);
	gettimeofday(&tv, NULL);
	info->time.start_time_s = tv.tv_sec;
	info->time.start_time_us = tv.tv_usec;
	init_rules(info, argv);
	init_philos(info);
	init_forks(info);
	set_forks(info);
}

int main(int argc, char **argv)
{
	t_info info;

	if (argc != 5 && argc != 6)
		printf ("invalid argument counts");
	else
	{
		init_info(&info, argv);
		philosophers(&info);
		free_info(&info);
	}
	return (0);
}
