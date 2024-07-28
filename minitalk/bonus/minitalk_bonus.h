/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:48:05 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/14 00:19:24 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	put_error(char *s, int fd);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	put_message(int sig);

#endif