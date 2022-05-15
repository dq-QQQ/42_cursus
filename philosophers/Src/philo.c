/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:27:01 by kyujlee           #+#    #+#             */
/*   Updated: 2022/05/15 18:41:06 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philo.h"

void	philosophers(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->rules.philo_num)
	{
		pthread_create(&info->philos[i].philo_thread, NULL,
			philo_func, &info->philos[i]);
		pthread_create(&info->philos[i].dead_monitor, NULL,
			dead_monitoring, &info->philos[i]);
		pthread_detach(info->philos[i].philo_thread);
		pthread_detach(info->philos[i].dead_monitor);
	}
	if (info->rules.least_eat != -1)
	{
		pthread_create(&info->eating_done_monitor, NULL,
			eating_done_monitoring, info);
		pthread_detach(info->eating_done_monitor);
	}
}

void	init_info(t_info *info, char **argv)
{
	info->eating_done_cnt = 0;
	info->philo_state = EVERYONE_ALIVE;
	init_time(info);
	init_rules(info, argv);
	init_forks(info);
	init_philos(info);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 5 && argc != 6)
		printf ("invalid argument counts");
	else
	{
		init_info(&info, argv);
		philosophers(&info);
		while (info.philo_state == EVERYONE_ALIVE)
			usleep(100);
		free_info(&info);
	}
	return (0);
}
