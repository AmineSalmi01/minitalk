/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:47:42 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/13 23:51:49 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	put_error(char *s, int fd)
{
	if (!s)
		return ;
	if (fd < 0)
		return ;
	if (*s)
		write(1, s, ft_strlen(s));
	exit(1);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			put_error("Error: Invalid PID\n", STDERR_FILENO);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + *str - 48;
		str++;
	}
	if (*str != '\0')
		put_error("Error: Invalid PID\n", STDERR_FILENO);
	return (res * sign);
}

void	put_message(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Message received by server\n", 28);
}
