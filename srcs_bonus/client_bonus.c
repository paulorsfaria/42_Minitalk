/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:32:53 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/25 09:32:53 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk_bonus.h"

static void	ft_check_delivery(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("bit delivered\n");
	else if (signal == SIGUSR2)
		ft_printf("char delivered\n");
}

static void	ft_send_bits(char c, int pid)
{
	int	bit;

	bit = 8;
	while (bit-- > 0)
	{
		if (c >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	i = 0;
	argc--;
	if (argc == 2)
	{
		pid = ft_atoi(argv[1]);
		if (!argv[2][0])
			return (0);
		while (argv[2][i] != '\0')
		{
			signal(SIGUSR1, ft_check_delivery);
			signal(SIGUSR2, ft_check_delivery);
			ft_send_bits(argv[2][i], pid);
			i++;
		}
		ft_send_bits('\0', pid);
	}
	else
	{
		ft_printf("\033[0;31mError\033[0m\n");
		ft_printf("\033[0;31mEx:./client_bonus <PID> <MESSAGE>\033[0m\n");
	}
	return (0);
}
