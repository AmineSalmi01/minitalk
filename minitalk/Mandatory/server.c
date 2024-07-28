/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:48:06 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/13 23:35:57 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *info, void *param)
{
	static int	i;
	static char	byte;
	static int	pid;

	(void)param;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		byte = 0;
		i = 0;
	}
	byte |= (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		write(1, &byte, 1);
		byte = 0;
		i = 0;
	}
	else
		byte = byte << 1;
}

int	main(int ac, char **av)
{
	struct sigaction	act;

	(void)av;
	if (ac != 1)
		put_error("Error: No args.\n", 2);
	else
	{
		act.sa_flags = SA_SIGINFO;
		act.sa_sigaction = signal_handler;
		ft_putnbr_fd(getpid(), 1);
		write(1, "\n", 1);
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		while (1)
			pause();
	}
	return (0);
}
