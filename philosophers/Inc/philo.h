/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:28:25 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/16 17:30:35 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_time
{
    long start_time_s;
    long start_time_us;
}				t_time;

typedef struct s_rules
{
    int philo_num;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int least_eat;
    
}				t_rules;

typedef struct s_philo
{
	int				i;
	int				eat_cnt;
    int				last_eating_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread_id;
}				t_philo;

typedef struct s_fork
{
    int i;
    int state;
    pthread_mutex_t	mutex_id;
}				t_fork;

typedef struct s_info
{
    int             dead_flag;
    pthread_mutex_t death_mutex_id;
    t_time          time;
	t_rules	        rules;
	t_philo			*philos;
	t_fork			*forks;
}				t_info;

enum e_state
{
	EAT = 0,
	THINK,
	SLEEP,
    FORK,
    FORK_ON,
    FORK_OFF,
    COMPLETE_EATING,
    EVERYONE_ALIVE,
    DEAD,
};


int			ft_atoi(const char *str);

#endif
