/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:24:11 by kyujlee           #+#    #+#             */
/*   Updated: 2021/09/27 15:35:37 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void sig_handler(int signum){
	static  unsigned char	byte ;
	static	int				bit_idx;

	if (signum == SIGUSR1)
		byte += 1 << (7 - bit_idx);
	if (++bit_idx == 8)
	{
		if (byte == '\0')
			write(1, "\n", 1);
		write(1, &byte, 1);
		bit_idx = 0;
		byte = 0;
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
