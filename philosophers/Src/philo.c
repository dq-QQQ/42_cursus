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
	info->dead_flag = EVERYONE_ALIVE;
	init_time(info);
	init_rules(info, argv);
	init_forks(info);
	init_philos(info);
}

int main(int argc, char **argv)
{
	t_info info;

	if (argc != 5 && argc != 6)
		printf ("invalid argument counts");
	else
	{
		init_info(&info, argv);
		//philosophers(&info);
		//free_info(&info);
	}
	return (0);
}
