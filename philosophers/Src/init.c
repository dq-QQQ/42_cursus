/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:46:39 by kyujlee           #+#    #+#             */
/*   Updated: 2022/05/10 22:46:41 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philo.h"

void init_time(t_info *info)
{
	struct timeval  tv;
	
	info->dead_flag = EVERYONE_ALIVE;
	pthread_mutex_init(&info->death_mutex_id, NULL);
	gettimeofday(&tv, NULL);
	info->time.start_time_s = tv.tv_sec;
	info->time.start_time_us = tv.tv_usec;
}

void init_rules(t_info *info, char **argv)
{
	info->rules.philo_num = ft_atoi(argv[1]);
	info->rules.time_to_die = ft_atoi(argv[2]);
	info->rules.time_to_eat = ft_atoi(argv[3]);
	info->rules.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] == NULL)
		info->rules.least_eat = -1;
	else
		info->rules.least_eat = ft_atoi(argv[5]);
}

void init_forks(t_info *info)
{
	int i;
	pthread_mutex_t tmp_mutex;

	i = -1;
	info->forks = (t_fork *)malloc(sizeof(t_fork) * info->rules.philo_num);
	while (++i < info->rules.philo_num)
	{
		pthread_mutex_init(&tmp_mutex, NULL);
		info->forks[i].i = i;
		info->forks[i].state = FORK_OFF;
		info->forks[i].mutex_id = tmp_mutex;
	}
}

void init_philos(t_info *info)
{
	int	i;

	i = -1;
	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->rules.philo_num);
	while (++i < info->rules.philo_num)
	{
		info->philos[i].i = i;
		info->philos[i].eat_cnt = 0;
		info->philos[i].last_eating_time = 0;
		info->philos[i].left_fork = &(info->forks[i]);
		if (i == info->rules.philo_num - 1)
			info->philos[i].right_fork = &(info->forks[0]);
		else
			info->philos[i].right_fork = &(info->forks[i + 1]);
	}
}