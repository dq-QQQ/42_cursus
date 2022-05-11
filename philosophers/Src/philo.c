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

int	curr_time(t_info *info)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec - info->time.start_time_s) * 1000
		+ (tv.tv_usec - info->time.start_time_us) / 1000);
}

int print_status_death(t_info *info, int status, int curr_i)
{
	t_philo			*philo;

	philo = &info->philos[curr_i];
	pthread_mutex_lock(&info->death_mutex_id);
	pthread_mutex_unlock(&philo->left_fork->mutex_id);
	pthread_mutex_unlock(&philo->right_fork->mutex_id);
	if (status == COMPLETE_EATING)
		info->dead_flag = COMPLETE_EATING;
	else if (status == EVERYONE_ALIVE)
	{
		info->dead_flag = DEAD;
		printf ("%d\t%d died\n", curr_time(info), curr_i + 1);
	}
	pthread_mutex_unlock(&info->death_mutex_id);
	return (0);
}

int print_status(t_info *info, int status, int curr_i)
{
	pthread_mutex_lock(&info->death_mutex_id);
	if (info->dead_flag != EVERYONE_ALIVE)
	{
		pthread_mutex_unlock(&info->death_mutex_id);
		return (0);
	}
	info->dead_flag = EVERYONE_ALIVE;
	if (status == SLEEP)
		printf ("%d\t%d is sleeping\n",
			curr_time(info), curr_i + 1);
	else if (status == EAT)
		printf ("%d\t%d is eating\n",
			curr_time(info), curr_i + 1);
	else if (status == THINK)
		printf ("%d\t%d is thinking\n",
			curr_time(info), curr_i + 1);
	else if (status == FORK)
		printf ("%d\t%d has taken a fork\n",
			curr_time(info), curr_i + 1);
	pthread_mutex_unlock(&info->death_mutex_id);
	return (1);
}

int		is_everyone_eat(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->rules.philo_num)
	{
		if (info->philos[i].eat_cnt != info->rules.least_eat)
			return (0);
	}
	return (1);
}

int philo_pause(t_info *info, int start, int curr_i)
{
	while (curr_time(info) - start < info->rules.time_to_die)
	{
		if (info->dead_flag != EVERYONE_ALIVE
			|| (curr_time(info) - info->philos[curr_i].last_eating_time
				> info->rules.time_to_die))
			return(0);
	}
	return (1);
}



static int	philo_one_fork(t_info *info, int curr_i)
{
	philo_pause(info, curr_time(info), curr_i);
	return (0);
}

int	philo_fork(t_info *info, int curr_i)
{
	t_philo			*philo;

	philo = &info->philos[curr_i];
	pthread_mutex_lock(&philo->left_fork->mutex_id);
	philo->left_fork->state = FORK_ON;
	if (curr_time(info) - philo->last_eating_time > info->rules.time_to_die)
		return (0);
	if (!print_status(info, FORK, curr_i))
		return (0);
	if (philo->left_fork == philo->right_fork)
		return (philo_one_fork(info, curr_i));
	pthread_mutex_lock(&philo->right_fork->mutex_id);
	philo->right_fork->state = FORK_ON;
	if (curr_time(info) - philo->last_eating_time > info->rules.time_to_die)
		return (0);
	if (!print_status(info, FORK, curr_i))
		return (0);
	return (1);
}

int	philo_eat(t_info *info, int curr_i)
{
	t_philo			*philo;

	philo = &info->philos[curr_i];
	if (print_status(info, EAT, curr_i) || !philo_pause(info, curr_time(info), curr_i))
		return (0);
	philo->last_eating_time = curr_time(info);
	pthread_mutex_unlock(&philo->left_fork->mutex_id);
	philo->left_fork->state = FORK_OFF;
	pthread_mutex_unlock(&philo->right_fork->mutex_id);
	philo->right_fork->state = FORK_OFF;
	if (info->rules.least_eat != -1)
	{
		philo->eat_cnt++;
		if (is_everyone_eat(info))
			return (0);
	}
	return (1);
}

int	philo_sleep(t_info *info, int curr_i)
{
	if (info->dead_flag != EVERYONE_ALIVE)
		return (0);
	if (!print_status(info, SLEEP, curr_i))
		return (0);
	if (!philo_pause(info, curr_time(info), curr_i))
		return (0);
	return (1);
}

void	*philo_routine(void *data)
{
	t_info *info;
	int	tmp;

	info = (t_info *)data;
	tmp = info->curr_i;

	while (info->dead_flag == EVERYONE_ALIVE)
	{
		if (!philo_fork(info, tmp) || !philo_eat(info, tmp) || !philo_sleep(info, tmp))
			break ;
		if (info->dead_flag != EVERYONE_ALIVE)
			break ;
		else
			if (!print_status(info, THINK, tmp))
				break;
	}
	if (info->dead_flag == EVERYONE_ALIVE)
	{
		if (is_everyone_eat(info))
			print_status_death(info, COMPLETE_EATING, tmp);
		else
			print_status_death(info, DEAD, tmp);
		return (NULL);
	}
	pthread_mutex_unlock(&info->philos[tmp].left_fork->mutex_id);
	pthread_mutex_unlock(&info->philos[tmp].right_fork->mutex_id);
	pthread_mutex_unlock(&info->death_mutex_id);
	return (NULL);
}

void philosophers(t_info *info)
{
	int			i;
	pthread_t	tmp_thread;
	void		**thread_ret;

	i = -1;
	thread_ret = NULL;
	while (++i < info->rules.philo_num)
	{
		if (i % 2)
			usleep(50);
		info->curr_i = i;
		pthread_create(&tmp_thread, NULL, philo_routine, info);
		info->philos[i].thread_id = tmp_thread;
	}
	i = -1;
	while (++i < info->rules.philo_num)
		pthread_join(info->philos[i].thread_id, thread_ret);
}

void init_info(t_info *info, char **argv)
{
	info->curr_i = -1;
	info->dead_flag = EVERYONE_ALIVE;
	pthread_mutex_init(&info->death_mutex_id, NULL);
	init_time(info);
	init_rules(info, argv);
	init_forks(info);
	init_philos(info);
}

// void free_info(t_info *info)
// {
// }

int main(int argc, char **argv)
{
	t_info info;

	if (argc != 5 && argc != 6)
		printf ("invalid argument counts");
	else
	{
		init_info(&info, argv);
		philosophers(&info);
		// free_info(&info);
	}
	return (0);
}
