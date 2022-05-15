/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:41:46 by kyujlee           #+#    #+#             */
/*   Updated: 2022/05/15 16:41:48 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philo.h"

int	curr_time(t_info *info)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec - info->time.start_time_s) * 1000
		+ (tv.tv_usec - info->time.start_time_us) / 1000);
}

void	philo_pause(t_info *info, int start_time, int end_time)
{
    while (curr_time(info) < start_time + end_time)
        usleep(100);
}

void	ft_printf(char *str, t_philo *philo)
{
	if (philo->info->philo_state != EVERYONE_ALIVE)
		return ;
	printf("%d\t%d %s\n", curr_time(philo->info), philo->id + 1, str);
}
