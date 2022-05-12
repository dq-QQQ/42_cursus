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
# include <stdlib.h>
# include <stdio.h>

typedef struct s_info t_info;

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
	int				        id;
	int				        eat_cnt;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	pthread_t		        philo_thread;
    t_info                  *info;
}				t_philo;

typedef struct s_info
{
    int                 stop_flag;
    int                 eating_done_cnt;
    pthread_t           monitor;
    t_time              time;
	t_rules	            rules;
    pthread_mutex_t	    *forks;
    int                 *state;
	t_philo			    *philos;
}				t_info;

enum e_state
{
	EAT = 0,
	THINK,
	SLEEP,
    FORK,
    EVERYONE_ALIVE,
    COMPLETE_EATING,
    DEAD,
};

/*
** utils1.c --- related to libft
*/
int			ft_atoi(const char *str);

/*
** init.c --- related to init_info
*/
void init_time(t_info *info);
void init_rules(t_info *info, char **argv);
void init_forks(t_info *info);
void init_philos(t_info *info);


#endif
