/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:11:24 by ftroise           #+#    #+#             */
/*   Updated: 2024/02/25 14:34:32 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_c(char c, int bit_no, int pid)
{
	int	current_bit;

	while (bit_no < 8)
	{
		current_bit = (c & (1 << bit_no)) != 0;
		if (current_bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_no++;
		usleep(1000);
	}
}

void	check_bit(int pid, char *msg)
{
	int	i;
	int	bit_no;

	i = 0;
	while (msg[i])
	{
		bit_no = 0;
		send_c(msg[i], bit_no, pid);
		i++;
	}
}

void	send_signal(int i)
{
	(void)i;
	ft_printf("Mex spedito al server");
}

int	main(int argc, char **argv)
{
	pid_t	c;

	c = 0;
	if (argc != 3)
	{
		ft_printf("Errore\nUtilizzo: ./client PID_SERVER MESSAGGIO\n");
		exit(0);
	}
	c = ft_atoi(argv[1]);
	check_bit(c, argv[2]);
	signal(SIGUSR1, &send_signal);
	send_c('\n', 0, c);
	send_c('\0', 0, c);
}
