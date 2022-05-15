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
    long                    last_eating_time;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	pthread_t		        philo_thread;
    pthread_t               dead_monitor;
    t_info                  *info;
}				t_philo;

typedef struct s_info
{
    int                 eating_done_cnt;
    int                 philo_state;
    pthread_t           eating_done_monitor;
    t_time              time;
	t_rules	            rules;
    pthread_mutex_t     *forks;
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
** init.c --- related to init_info
*/
void init_time(t_info *info);
void init_rules(t_info *info, char **argv);
void init_forks(t_info *info);
void init_philos(t_info *info);

/*
** philo_func.c --- related to routine
*/
void    *philo_func(void *data);
void	*philo_pickup(t_philo *philo);
void	*philo_eating(t_philo *philo);
void	*philo_thinking(t_philo *philo);
void	*philo_sleeping(t_philo *philo);

/*
** monitoring.c --- related to monitor
*/
void    *dead_monitoring(void *data);
void    *eating_done_monitoring(void *data);


/*
** utils1.c --- related to libft
*/
int			ft_atoi(const char *str);

/*
** utils1.c --- related to philo's utils
*/
int	    curr_time(t_info *info);
void	ft_printf(char *str, t_philo *philo);
void	philo_pause(t_info *info, int start_time, int end_time);




#endif
