/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:11:24 by ftroise           #+#    #+#             */
/*   Updated: 2024/02/25 14:33:55 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int segn, siginfo_t *info, void *x)
{
	static int	value;
	static int	bit_at;

	(void)x;
	if (segn == SIGUSR1)
		value += 1 << bit_at;
	bit_at++;
	if (bit_at == 8)
	{
		write(1, &value, 1);
		if (value == '\0')
			kill(info->si_pid, SIGUSR1);
		value = 0;
		bit_at = 0;
	}
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server attivo\nPID: %d\n", pid);
	act.sa_sigaction = &sig_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	sigemptyset(&act.sa_mask);
	while (1)
		pause();
}
