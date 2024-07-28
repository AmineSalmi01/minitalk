/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:42:20 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/13 23:18:52 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signale_s(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		put_error("Error: Invalid args\n", STDERR_FILENO);
	i = 0;
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		put_error("Error: Invalid PID\n", STDERR_FILENO);
	signal(SIGUSR1, put_message);
	while (av[2][i])
	{
		signale_s(pid, av[2][i]);
		i++;
	}
	signale_s(pid, '\0');
	return (0);
}
