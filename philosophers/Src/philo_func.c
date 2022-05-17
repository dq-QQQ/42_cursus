/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:41:59 by kyujlee           #+#    #+#             */
/*   Updated: 2022/05/15 18:43:14 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philo.h"

void	*philo_pickup(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_printf("has taken a fork", philo);
	pthread_mutex_lock(philo->right_fork);
	ft_printf("has taken a fork", philo);
	return (philo_eating);
}

void	*philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->dying_and_eating);
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->info->rules.least_eat)
		philo->info->eating_done_cnt++;
	philo->last_eating_time = curr_time(philo->info);
	ft_printf("is eating", philo);
	philo_pause(philo->info, curr_time(philo->info),
		philo->info->rules.time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->dying_and_eating);
	return (philo_sleeping);
}

void	*philo_thinking(t_philo *philo)
{
	ft_printf("is thinking", philo);
	return (philo_pickup);
}

void	*philo_sleeping(t_philo *philo)
{
	ft_printf("is sleeping", philo);
	philo_pause(philo->info, curr_time(philo->info),
		philo->info->rules.time_to_sleep);
	return (philo_thinking);
}

void	*philo_func(void *data)
{
	void	*(*func)(t_philo *philo);
	t_philo	*philo;

	philo = (t_philo *)data;
	func = philo_pickup;
	if (philo->id % 2)
		usleep(500);
	while (philo->info->philo_state == EVERYONE_ALIVE)
		func = func(philo);
	return (NULL);
}
