/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:31:42 by kyujlee           #+#    #+#             */
/*   Updated: 2021/09/27 15:01:34 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, char one_byte)
{
	unsigned char	bitmask;
	unsigned char	bit;

	bitmask = 1 << 7;
	while (bitmask >= 1)
	{
		bit = bitmask & one_byte;
		if (bit == bitmask)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bitmask >>= 1;
		usleep(100);
	}
}

void	send_msg(int pid, char *msg)
{
	int byte;

	byte = 0;
	while (msg[byte])
	{
		send_bit(pid, msg[byte]);
		byte++;
	}
	send_bit(pid, '\0');
}

int main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
		ft_error();
	pid = ft_atoi(argv[1]);
	send_msg(pid, argv[2]);
	return (0);
}
