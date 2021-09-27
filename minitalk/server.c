/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:24:11 by kyujlee           #+#    #+#             */
/*   Updated: 2021/09/27 15:23:50 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void sig_handler(int signum){
	static  unsigned char	bit ;
	static	int				bit_num;

	if (signum == SIGUSR1)
		bit += 1 << (7 - bit_num);
	if (++bit_num == 8)
	{
		if (bit == '\0')
			write(1, "\n", 1);
		write(1, &bit, 1);
		bit_num = 0;
		bit = 0;
	}
}



int main()
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
