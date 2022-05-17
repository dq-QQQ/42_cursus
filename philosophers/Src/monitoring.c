/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:38:03 by kyujlee           #+#    #+#             */
/*   Updated: 2022/05/15 18:39:47 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philo.h"

void	*dead_monitoring(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->info->philo_state == EVERYONE_ALIVE)
	{
		pthread_mutex_lock(&philo->dying_and_eating);
		if (philo->last_eating_time + philo->info->rules.time_to_die
			<= curr_time(philo->info))
		{
			philo->info->philo_state = DEAD;
			printf("%d\t%d %s\n", curr_time(philo->info), philo->id + 1, "died");
			break ;
		}
		pthread_mutex_unlock(&philo->dying_and_eating);
		usleep(500);
	}
	return (NULL);
}

void	*eating_done_monitoring(void *data)
{
	t_info	*info;

	info = (t_info *)data;
	while (info->eating_done_cnt != info->rules.philo_num)
		usleep(500);
	info->philo_state = COMPLETE_EATING;
	printf("COMPLETE EATING\n");
	return (NULL);
}
